#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000;
int n, m;
string s;

vector<int> g[2*MAX_N];
bool vis[2*MAX_N];
bool path[2*MAX_N];

int main()
{
  cin >> n >> m >> s;
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    if (s[u-1] == s[v-1]) {
      g[u-1].push_back(n+v-1);
      if (u != v)
        g[v-1].push_back(n+u-1);
    }
    if (s[u-1] != s[v-1]) {
      g[n+u-1].push_back(v-1);
      g[n+v-1].push_back(u-1);
    }
  }

  fill_n(vis, 2*n, false);
  for (int i = 0; i < 2*n; i++) {
    if (vis[i]) continue;
    stack<pair<int,int> > st;
    st.push(make_pair(i,0));
    vis[i] = true;
    path[i] = true;
    while (!st.empty()) {
      auto p = st.top(); st.pop();
      if (p.second < g[p.first].size()) {
        int c = g[p.first][p.second];
        st.push(make_pair(p.first, p.second+1));
        if (path[c]) {
          cout << "Yes" << endl;
          return 0;
        }
        if (vis[c]) continue;
        vis[c] = true;
        path[c] = true;
        st.push(make_pair(c,0));
      } else {
        path[p.first] = false;
      }
    }
  }
  cout << "No" << endl;

  return 0;
}
