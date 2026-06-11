#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, C;
  cin >> N >> C;
  vector<vector<pair<int, int>>> R(C);
  for (int i = 0; i < N; i++){
    int s, t, c;
    cin >> s >> t >> c;
    c--;
    R[c].push_back(make_pair(s, t));
  }
  for (int i = 0; i < C; i++){
    sort(R[i].begin(), R[i].end());
  }
  vector<vector<pair<int, int>>> R2(C);
  for (int i = 0; i < C; i++){
    if (!R[i].empty()){
      R2[i].push_back(R[i][0]);
      int cnt = R[i].size();
      for (int j = 1; j < cnt; j++){
        if (R2[i].back().second == R[i][j].first){
          R2[i].back().second = R[i][j].second;
        } else {
          R2[i].push_back(R[i][j]);
        }
      }
    }
  }
  vector<int> cnt(1000002, 0);
  for (int i = 0; i < C; i++){
    int sz = R2[i].size();
    for (int j = 0; j < sz; j++){
      cnt[R2[i][j].first - 1]++;
      cnt[R2[i][j].second]--;
    }
  }
  for (int i = 1; i <= 100001; i++){
    cnt[i] += cnt[i - 1];
  }
  int ans = 0;
  for (int i = 0; i <= 100001; i++){
    ans = max(ans, cnt[i]);
  }
  cout << ans << endl;
}