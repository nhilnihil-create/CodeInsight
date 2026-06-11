#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll modpow(ll a,ll n){
  if(n==0)return 1;
  if(n%2==0){
    ll t=modpow(a,n/2);
    return (t*t)%MOD;
  }
  return a*modpow(a,n-1)%MOD;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n,a;
  cin >> n >> a;
  n%=500;
  if(n<=a)cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;     
}
