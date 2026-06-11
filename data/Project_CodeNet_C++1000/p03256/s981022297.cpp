#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<int>> g(n);
  vector<vector<int>> deg(2, vector<int>(n));
  set<pair<int, int>> st;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
    deg[s[b] - 'A'][a]++;
    deg[s[a] - 'A'][b]++;
  }

  for (int i = 0; i < n; ++i) {
    st.insert(make_pair(min(deg[0][i], deg[1][i]), i));
  }

  vector<bool> live(n, true);
  for (;;) {
    if (st.empty()) break;
    auto it = st.begin();
    if (it->first != 0) break;
    int a = it->second;
    live[a] = false;
    st.erase(st.begin());
    for (int i : g[a]) {
      if (!live[i]) continue;
      st.erase(st.find(make_pair(min(deg[0][i], deg[1][i]), i)));
      deg[s[a] - 'A'][i]--;
      st.insert(make_pair(min(deg[0][i], deg[1][i]), i));
    }
  }

  cout << (st.empty() ? "No" : "Yes") << endl;

  return 0;
}
