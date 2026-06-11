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
  int n,T; cin >> n >> T;
  vector<int> c(n),t(n);
  rep(i,n){
    cin >> c[i] >> t[i];
  }
  int ans = 1<<29;
  rep(i,n){
    if(t[i] > T) continue;
    ans = min(ans, c[i]);
  }
  if(ans == 1<<29){
    cout << "TLE" << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
