#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  int maxi = *max_element(all(l));
  int sum = accumulate(all(l), 0) - maxi;
  if (maxi < sum) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
