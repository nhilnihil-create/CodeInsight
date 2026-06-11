#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll gcd(ll x, ll y){
  if(x%y==0)return y;
  return gcd(y,x%y);
}
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  ll r,g,b,n;
  cin >> r >> g >> b >> n;
  ll ans=0;
  for(ll i=0;i*r<=n;i++){
    for(ll j=0;j*g+i*r<=n;j++){
      ll k=n-i*r-j*g;
      if(k%b==0)ans++;
    }
  }
  cout << ans << endl;
}
