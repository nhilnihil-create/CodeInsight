#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;

int main() {
  LL n;
  vector<char> s;

  cin >> n;
  string str;
  cin >> str;
  for (LL i = 0; i < n; ++i) {
    const char c = str[i];
    s.push_back(c);
  }

  vector<LL> nw;
  for (LL i = 0; i < n; ++i) {
    if (i == 0) {
      nw.push_back((LL)0);
    } else {
      auto this_nw = nw.back();
      if (s[i - 1] == 'W') {
        this_nw++;
      }
      nw.push_back(this_nw);
    }
//    cout << nw.back() << "\n";
  }

  vector<LL> ne;
  for (LL i = n - 1; i >= 0; --i) {
    if (i == n - 1) {
      ne.push_back((LL)0);
    } else {
      auto this_ne = ne.back();
      if (s[i + 1] == 'E') {
        this_ne++;
      }
      ne.push_back(this_ne);
    }
  }
  reverse(ne.begin(), ne.end());

  vector<LL> cost;
  for (LL i = 0; i < n; ++i) {
    cost.push_back(nw[i] + ne[i]);
//    cout << nw[i] << " " << ne[i] << endl;
  }
  auto min_cost_it = std::min_element(cost.begin(), cost.end());

  cout << *min_cost_it << endl;
}

