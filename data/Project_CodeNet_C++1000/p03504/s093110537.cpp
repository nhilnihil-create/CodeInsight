#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main(){
  int n, c;
  cin >> n >> c;
  vector<vector<int>> timet(n, vector<int>(3));
  for(int i=0; i<n; ++i){
    cin >> timet[i][0] >> timet[i][1] >> timet[i][2];
  }
  sort(timet.begin(),timet.end());
  
  vector<P> rec(c,make_pair(0,0));
  for(int i=0; i<n; ++i){
    for(int j=0; j<c; ++j){
      int st = rec[j].first;
      bool st3 = false;
      if(st == timet[i][0] && rec[j].second == timet[i][2]) st3 = true;
      if(st == 0 || st < timet[i][0] || st3){
        rec[j] = make_pair(timet[i][1],timet[i][2]);
        break;
      }
    }
  }
  int ans = 0;
  for(int i=0; i<c; ++i){
    if(rec[i].first != 0) ++ans;
  }
  cout << ans << endl;
}