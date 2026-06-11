#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n;
  cin >> n;
  int arr[n + 1], bit[25][n + 1];
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  for (int p = 0; p < 25; p++)
    bit[p][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int p = 0; p < 25; p++) bit[p][i] = bit[p][i - 1];
    int num = arr[i], p = 0;
    while (num) {
      if (num & 1)
        bit[p][i]++;
      num >>= 1;
      p++;
    }
  }
  int e = 1;
  long long ans = 0;
  for (int s = 1; s <= n; s++) {
    // shift e to right s.t. all bits either never appear or only once appear between s to e
    while (true) {
      bool stop = false;
      for (int p = 0; p < 25; p++) {
        if (bit[p][e] - bit[p][s - 1] > 1)
          stop = true;
      }
      if (stop) {
        e--;
        break;
      }
      else if (e == n)
        break;
      else
        e++;
    }
    ans += e - s + 1;
  }
  cout << ans;
  return 0;
}