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
  int N,M,X,Y; cin >> N >> M >> X >> Y;
  vector<int> x(N), y(M);
  rep(i,N) cin >> x[i];
  rep(i,M) cin >> y[i];
  int xmax = X;
  int ymin = Y;
  rep(i,N) xmax = max(xmax, x[i]);
  rep(i,M) ymin = min(ymin, y[i]);
  if(xmax < ymin) cout << "No War" << endl;
  else cout << "War" << endl;
  return 0;
}
