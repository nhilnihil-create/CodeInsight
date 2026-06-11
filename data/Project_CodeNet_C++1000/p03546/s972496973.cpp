#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define P pair<int, int>
#define Pl pair<ll, ll>
#define dvec vector<vector<ll>>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

void
Warshall_Floyd(int V, vector<vector<int>> &G)
{
  rep(i, 0, V){
    rep(k, 0, V){
      rep(l, 0, V){
        chmin(G[k][l], G[k][i] + G[i][l]);
      }
    }
  }
}

int main()
{
  int H, W; cin >> H >> W;
  vector<vector<int>> cost(10, vector<int>(10));
  rep(i, 0, 10) rep(k, 0, 10) cin >> cost[i][k];
  vector<vector<int>> wall(H, vector<int>(W));
  rep(i, 0, H) rep(k, 0, W) cin >> wall[i][k];

  Warshall_Floyd(10, cost);
  
  ll ans = 0;
  rep(i, 0, H){
    rep(k, 0, W){
      if(wall[i][k] != -1) ans += cost[wall[i][k]][1];
    }
  }
  
  cout << ans << endl;
}