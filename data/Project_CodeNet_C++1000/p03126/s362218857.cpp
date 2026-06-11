#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> f(m);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      f[a - 1]++;
    }
  }
  cout << count(all(f), n) << endl;
  return 0;
}