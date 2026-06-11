#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using P = pair<int, int>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  vector<P> ab(N), cd(N);
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    ab[i] = P(a, b);
  }
  for (int i = 0; i < N; i++) {
    int c, d; cin >> c >> d;
    cd[i] = P(c, d);
  }
  sort(cd.begin(), cd.end());

  vector<bool> check(N);
  for (int i = 0; i < N; i++) {
    int& c = cd[i].first;
    int& d = cd[i].second;
    int k = -1;
    for (int j = 0; j < N; j++) {
      if (check[j]) continue;
      int& a = ab[j].first;
      int& b = ab[j].second;
      if (c > a && d > b && (k < 0 || b > ab[k].second))
        k = j;
    }
    if (k >= 0) check[k] = true;
  }

  int ans = 0;
  for (int i = 0; i < N; i++) if (check[i]) ans++;
  cout << ans << "\n";
}