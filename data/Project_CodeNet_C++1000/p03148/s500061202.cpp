//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const int MOD = 1000000007;
//const int MOD = 998244353;
template<class T> inline int add(T& a, T b, T M = MOD){a=(a+M)%M;b=(b+M)%M;a=(a+b)%M;return a;};
template<class T> inline int mul(T& a, T b, T M = MOD){if(a>=M)a%=M;if(b>=M)b%=M;a*=b;if(a>=M)a%=M;return a;};
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
const string abc="abcdefghijklmnopqrstuvwxyz";
const string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

////////////////////////////////////////////////////////////////////
///////////////////////___modpow___////////////////////
ll modpow(ll a,  ll n, const ll &MOD = MOD){
  ll ret = n == 0 ? 1 : modpow(a, n/2, MOD);
  (ret *= ret) %= MOD;
  if(n%2)((ret *= a) %= MOD);
  return ret;
}
///////////////////////___modinv___////////////////////
ll modinv(ll d, const ll &MOD = MOD){
  return modpow(d, MOD-2, MOD);
}
////////////////////////////////////////////////////////////////////

int n,k, ans, sum;P p[110000];
priority_queue<P, vector<P>, greater<P>> que;
int cnt[110000];
signed main(){
  cin>>n>>k;
  rep(i,n){
    cin>>p[i].second>>p[i].first;
  }
  sort(p,p+n,greater<P>());
  int v = 0;
  rep(i,k){
    ans += p[i].first;
    sum += p[i].first;
    if(cnt[p[i].second] == 0)v++;
    cnt[p[i].second]++;
    que.push(p[i]);
  }
  ans += v*v;
  repd(i, k, n){
    int t = p[i].second, d = p[i].first;
    if(cnt[t] >= 1)continue;
    int b = false;
    while(!que.empty()){
      if(cnt[que.top().second] > 1){
        b = true;v++;
        sum -= que.top().first;
        sum += d;
        cnt[que.top().second]--;
        cnt[t]++;
        que.pop();
        que.push(p[i]);
        break;
      }
      que.pop();
    }
    if(b){
      chmax(ans, sum+v*v);
    }
  }
  cout << ans << endl;
}
