#include <iostream>
#include <vector>

using namespace std;

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<pair<int, int>> edges;
  int fsum = n;
  if (n % 2 == 0) fsum++;

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (i + j != fsum) {
	edges.push_back(make_pair(i, j));
      }
    }
  }

  cout << (int) edges.size() << '\n';
  for (auto pr : edges) {
    cout << pr.first << " " << pr.second << '\n';
  }
}
