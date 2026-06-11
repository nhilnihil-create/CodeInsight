#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
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


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n;
  cin >> n;
  vvl f(n,vector<ll>(10));
  vvl p(n,vector<ll>(11));
  rep(i,n)rep(j,10) cin>>f[i][j];
  rep(i,n)rep(j,11) cin >> p[i][j];
  
  ll ans=-INF;
  for(int bit=0;bit<(1<<10);bit++){
    if(bit==0)continue;   
    ll res=0;
    rep(j,n){
      ll cnt=0;
      rep(i,10){
        if((bit & (1<<i)) && f[j][i])cnt++;
      }
      res+=p[j][cnt];
    }
    chmax(ans,res);
  }
  cout << ans << endl;
      
        
  
          
}
