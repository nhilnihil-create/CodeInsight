#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];

  ll sum_a = 0, sum_b = 0;
  for (int i = 0; i < n; ++i)
    sum_a += a[i];
  for (int i = 0; i < n; ++i)
    sum_b += b[i];

  ll cnt = sum_b - sum_a;

  ll cnt_1 = 0, cnt_2 = 0;
  for (int i = 0; i < n; ++i) {
    int x = b[i] - a[i];
    if (x < 0)
      cnt_1 += abs(x);
    else
      cnt_2 += (x + 1) / 2;
  }

  if (cnt >= cnt_1 && cnt >= cnt_2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}