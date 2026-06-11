#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int cnt_even = 0, cnt_odd = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a & 1)
      cnt_odd++;
    else
      cnt_even++;
  }

  ll all_case = (ll)pow(3, n);
  ll odd_case = (ll)pow(2, cnt_even);
  ll ans;
  cout << all_case - odd_case << endl;
}