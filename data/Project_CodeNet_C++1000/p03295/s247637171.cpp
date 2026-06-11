#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  int n,m; cin >> n >> m;
  vector<P> g(m);
  for(int i = 0; i < m; i++){
    int a,b; cin >> a >> b;
    g[i] = P(b,a);
  }
  sort(g.begin(), g.end());
  
  int left = g[0].first;
  int ans = 1;
  for(int i = 1; i < m; i++){
    if(left <= g[i].second){
      ans++;
      left = g[i].first;
    }
  }
  cout << ans << endl;
  return 0;
}
