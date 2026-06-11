#include <bits/stdc++.h>
using namespace std;
struct edge{
  int from, to, cost;
  edge(int a, int b, int c) {
    from = a;
    to = b;
    cost = c;
  }
};

int main() {
  int l;
  cin >> l;
  vector<edge> ans;
  for (int i = 2; i <= 19; i++) {
    ans.push_back(edge(i, i + 1, (1 << (19 - i))));
    ans.push_back(edge(i, i + 1, 0));
  }
  int ll = 0;
  while (l) {
    for (int i = 18; i >= 0; i--) {
      if (l >= (1 << i)) {
        ans.push_back(edge(1, 20 - i, ll));
        l -= (1 << i);
        ll += (1 << i);
        break;
      }
    }
  }
  cout << "20 " << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].from << " " << ans[i].to << " " << ans[i].cost << endl;
  }
  return 0;
}
