#include <bits/stdc++.h>
using namespace std;

bool custom (vector<int> &a, vector<int> &b) {
  return (a.size() < b.size());
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> r(n);
  vector<pair<int, int>> b(n);
  vector<vector<int>> rpp(n);
  vector<vector<int>> bpp(n);
  for(int i=0;i<n;i++) {
    cin >> r[i].first >> r[i].second;
  }
  for(int i=0;i<n;i++) cin >> b[i].first >> b[i].second;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      if(r[i].first < b[j].first && r[i].second < b[j].second) {
        rpp[i].emplace_back(j);
        bpp[j].emplace_back(i);
      }
    }
  }

  vector<vector<int>> rp = rpp;
  vector<vector<int>> bp = bpp;

  sort(rp.begin(), rp.end(), custom);

  int ans = 0;
  vector<bool> used(n);
  for(int i=0;i<n;i++) {
    int partner = -1;
    int minSize = 101;
    for(int j=0;j<rp[i].size();j++) {
      if(used[rp[i][j]]) continue;
      if(bp[rp[i][j]].size() < minSize) {
        partner = rp[i][j];
        minSize = bp[rp[i][j]].size();
      }
    }
    if(partner == -1) continue;
    ans++;
    used[partner] = true;
  }

  sort(bp.begin(), bp.end(), custom);

  int ans2 = 0;
  vector<bool> used2(n);
  for(int i=0;i<n;i++) {
    int partner = -1;
    int minSize = 101;
    for(int j=0;j<bp[i].size();j++) {
      if(used2[bp[i][j]]) continue;
      if(rpp[bp[i][j]].size() < minSize) {
        partner = bp[i][j];
        minSize = rpp[bp[i][j]].size();
      }
    }
    if(partner == -1) continue;
    ans2++;
    used2[partner] = true;
  }

  cout << max(ans, ans2) << endl;
}