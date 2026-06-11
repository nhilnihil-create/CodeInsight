#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);
  
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n);
  for(int i=0;i<m;++i) {
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> sel(n, -1);
  sel[0] = 0;
  bool bigraph = true;
  stack<pair<int, bool>> st;
  st.push(make_pair(0, 1));
  while(bigraph && !st.empty()) {
    pair<int, int> p = st.top(); st.pop();
    int now = p.first;
    bool col = p.second;
    int sz = g[now].size();
    for(int i=0;i<sz;++i) {
      int next = g[now][i];
      if(sel[next] == -1) {
        sel[next] = col;
        st.push(make_pair(next, !col));
      } else if(sel[next] != col) {
        bigraph = false;
        break;
      }
    }
  }

  if(bigraph) {
    ll cnt1 = 0, cnt2 = 0;
    int sz = sel.size();
    for(int i=0;i<sz;++i) {
      if(sel[i] == 0) cnt1++;
    }
    cnt2 = n - cnt1;
    cout << cnt1 * cnt2 - (ll)m << endl;
  } else {
    cout << (ll)n * ((ll)n - 1) / 2 - (ll)m << endl;
  }
}
