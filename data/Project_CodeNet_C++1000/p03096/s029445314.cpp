#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> nw(n), last(200001, -1);
  nw[0] = 1;
  last[a[0]] = 0;
  for (int i = 1; i < n; ++i) {
    nw[i] = nw[i - 1];
    if (last[a[i]] != -1 && last[a[i]] != i - 1) {
      nw[i] = (nw[i] + nw[last[a[i]]]) % MOD;
    }
    last[a[i]] = i;
  }
  cout << nw[n - 1] << endl;
  return 0;
}
