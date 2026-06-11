#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const int MOD=1e9+7;
const ll INF=1e18;
const ll inf=1e9;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=100010;
      
 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  int n,c;
  cin >> n >> c;
  vector<vector<int>> imos(c,vector<int>(MAX,0));
  rep(i,n){
    int s,t,x;
    cin >> s >> t >> x;
    s--;
    x--;
    imos[x][s]++;
    imos[x][t]--;
  }
  rep(i,c)rep(j,MAX) imos[i][j+1] += imos[i][j];
  
  int ans = 0;
  rep(j,MAX){
    int cnt = 0;
    rep(i,c){
      if(imos[i][j])cnt++;
    }
    ans=max(ans,cnt);
  }
  
  cout << ans << endl;
  return 0;
}
