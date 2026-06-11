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

int h, w, n, sr, sc;string s, t;
signed main(){
  cin>>h>>w>>n>>sr>>sc>>s>>t;
  int a[4];
  a[0] = a[2] = 1;a[1] = w;a[3] = h;
  bool b = false;
  reverse(s.begin(), s.end());reverse(t.begin(),t.end());
  rep(i,n){
    if(t[i] == 'L')a[1]++;
    if(t[i] == 'R')a[0]--;
    if(t[i] == 'U')a[3]++;
    if(t[i] == 'D')a[2]--;
    chmax(a[0],1LL);chmin(a[1],w);chmax(a[2],1LL);chmin(a[3],h);
    if(s[i] == 'L')a[0]++;
    if(s[i] == 'R')a[1]--;
    if(s[i] == 'U')a[2]++;
    if(s[i] == 'D')a[3]--;
    if(a[0] > a[1] || a[2] > a[3])b = true;
  }
  b = b | !(a[0] <= sc && sc <= a[1] && a[2] <= sr && sr <= a[3]);
  cout << (b ? "NO" : "YES") << endl;
}
