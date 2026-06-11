#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;
int main(){
  int n,m;cin >> n >> m;
  vector<vector<int>> swi(m);
  rep(i,m){
    int k;cin >> k;
    rep(j,k){
      int s;cin >> s;
      --s;
      swi[i].push_back(s);
    }
  }
  vector<int> num(m);
  rep(i,m) cin >> num[i];
  int ans = 0;
  rep(bit,1<<n){
    bool flag = true;
    rep(i,m){
      int cnt = 0;
      rep(j,swi[i].size()) if(bit>>swi[i][j]&1) cnt++;
      if(cnt%2 != num[i]) {
        flag = false;
        break;
      }
    }
    if(flag) ans++;
  }
  cout << ans << endl;


}