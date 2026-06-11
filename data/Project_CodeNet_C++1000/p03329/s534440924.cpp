#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define pi acos(-1.0)
const ll INF = 1LL<<61;
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
  if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
  }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる




int main(){
  ll n;
  cin>>n;

  vector<ll> p(7);
  p[0]=1;
  repo(i,7){
    p[i]=9*p[i-1];
  }
  vector<ll> q(8);
  q[0]=1;
  repo(i,8){
    q[i]=6*q[i-1];
  }

  vector<ll> ans(100005,INF);
  ans[0]=0;
  rep(i,100005){
    chmin(ans[i+1],ans[i]+1);
    repo(j,7){
      if(i+p[j]<100005) chmin(ans[i+p[j]],ans[i]+1);
    }
    repo(j,8){
      if(i+q[j]<100005) chmin(ans[i+q[j]],ans[i]+1);
    }  
  }

  cout << ans[n] << endl;
}