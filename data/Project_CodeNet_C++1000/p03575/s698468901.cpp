#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<pair<int, int>> v;
vector<int> nodeGroup(51, -1);

bool decideGroup(int start, int k, vector<bool> check, unordered_set<int>& s,
                 vector<unordered_set<int>> vg) {
  for (auto x : vg[k]) {
    vg[x].erase(k);
    if (start == x) {
      // cout << start << " " << k <<endl;
      return true;
    }
    if (!check[x]) {
      check[x] = true;
      if (decideGroup(start, x, check, s, vg)) {
        s.insert(x);
        return true;
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  cin >> N >> M;
  vector<unordered_set<int>> vg(51);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v.emplace_back(a, b);
    vg[a].insert(b);
    vg[b].insert(a);
  }
  unordered_set<int> s;
  int nodeNum = 0;
  for (int i = 0; i < N; i++) {
    if (nodeGroup[i] == -1) {
      s.clear();
      s.insert(i);
      vector<bool> check(51, false);
      check[i] = true;
      decideGroup(i, i, check, s, vg);
      int newNodeNum = nodeNum;
      for (auto x : s) {
        if (nodeGroup[x] != -1) {
          newNodeNum = nodeGroup[x];
        }
      }
      for (auto x : s) {
        nodeGroup[x] = newNodeNum;
      }
      nodeNum++;
    }
  }
  for (int i = 0; i < N; i++) {
    // cout << nodeGroup[i] <<endl;
  }

  int ans = 0;
  for (int i = 0; i < M; i++) {
    if (nodeGroup[v[i].first] != nodeGroup[v[i].second]) {
      ans++;
    }
  }
  cout << ans << endl;
}
