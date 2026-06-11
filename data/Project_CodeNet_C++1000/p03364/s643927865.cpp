#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  int good = 0;
  for (int i = 0; i < n; i++) {
    vector<string> g = grid;
    for (int j = 0; j < n; j++) {
      g[j] = grid[(i + j) % n];
    }

    bool ok = true;
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (g[j][k] != g[k][j]) {
          ok = false;
        }
      }
    }
    if (ok)
      good++;
  }
  cout << good * n << endl;
}
