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
  
  int n;
  cin >> n;
  vector<int>sum1(n+1,0),sum2(n+1,0);
  rep(i,n){
    int a;
    cin >> a;
    sum1[i+1]=sum1[i]+a;
  }
  rep(i,n){
    int a;
    cin >> a;
    sum2[i+1]=sum2[i]+a;
  }
  int ans=0;
  rep(i,n){
    ans=max(sum1[i+1]-sum1[0]+sum2[n]-sum2[i],ans);
  }
  cout << ans << endl;
  return 0;     
}
