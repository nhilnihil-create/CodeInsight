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
  vector<int> ans(m);
  rep(i,n){
    int k; cin >> k;
    rep(j,k){
      int a; cin >> a;
      a--;
      ans[a]++;
    }
  }
  int cnt = 0;
  rep(i,m){
    if(ans[i] == n) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
