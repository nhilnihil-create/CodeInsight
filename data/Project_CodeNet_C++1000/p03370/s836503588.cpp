#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> m(n);
  int sum = 0, mini=1e9;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    sum += m[i];
    mini = min(mini, m[i]);
  }
  x -= sum;
  cout << n + floor(x / mini) << endl;
  return 0;
}