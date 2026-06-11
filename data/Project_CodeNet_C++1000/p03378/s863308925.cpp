#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  int left = 0, right = 0;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    if (a < x) left++;
    else right++;
  }
  cout << min(left, right) << endl;
  return 0;
}