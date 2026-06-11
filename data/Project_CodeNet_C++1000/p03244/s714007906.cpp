#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  vector<int> vodd(100001, 0), veven(100001, 0);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (i % 2 == 0)
      veven[v]++;
    else
      vodd[v]++;
  }

  auto even_iter = veven.begin() + 1;
  auto even_iter_2nd = veven.begin();
  auto odd_iter = vodd.begin() + 1;
  auto odd_iter_2nd = vodd.begin();

  for (auto iter = veven.begin() + 2; iter != veven.end(); ++iter) {
    if ((*even_iter) <= (*iter)) {
      even_iter_2nd = even_iter;
      even_iter = iter;
    } else if ((*even_iter_2nd) <= (*iter)) {
      even_iter_2nd = iter;
    }
  }
  for (auto iter = vodd.begin() + 2; iter != vodd.end(); ++iter) {
    if ((*odd_iter) <= (*iter)) {
      odd_iter_2nd = odd_iter;
      odd_iter = iter;
    } else if ((*odd_iter_2nd) <= (*iter)) {
      odd_iter_2nd = iter;
    }
  }

  if ((even_iter - veven.begin()) - (odd_iter - vodd.begin()) != 0) {
    cout << n - (*even_iter) - (*odd_iter) << endl;
  } else {
    cout << min(n - (*even_iter) - (*odd_iter_2nd),
                n - (*even_iter_2nd) - (*odd_iter))
         << endl;
  }
}
