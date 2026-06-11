#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;


int main() {
  int n;
  cin >> n;
  rep(i,n) {
    rep(j,n) {
      if (4 * i + 7 * j == n) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
