#include <iostream>
#include <vector>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> k(n), mm(m, 0);
  vector<vector<int>> a(n);
  rep(i, 0, n) {
    cin >> k[i];
    rep(j, 0, k[i]) {
      int b;
      cin >> b;
      a[i].push_back(b-1);
      mm[b-1]++;
    }
  }
  int c = 0;
  rep(i, 0, m) {
    if(mm[i] == n) {
      c++;
    }
  }
  cout << c;
}
