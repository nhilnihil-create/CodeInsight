#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == -1) continue;
    if (a[i] == a[i + 1]) a[i + 1] = -1;
  }
  cout << count(all(a), -1) << endl;
  return 0;
}