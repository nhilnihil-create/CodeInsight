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
  
  int n,m;
  cin >> n >> m;
  vector<vector<ll>>a(n,vector<ll>(3));
  rep(i,n)rep(j,3) cin >> a[i][j];
  
  ll ans=0;
  for(int bit=0;bit<(1<<3);bit++){
    vector<ll>val(n);
    rep(i,n){
      ll res=0;
      rep(j,3){
        if(bit & (1<<j)){
          res+=a[i][j];
        }
        else{
          res-=a[i][j];
        }
      }
      val[i]=res;
    }
    sort(val.begin(),val.end(),greater<ll>());
    ll sum=0;
    rep(i,m) sum+=val[i];
    chmax(ans,sum);
  }
  cout << ans << endl;
      
        
}
