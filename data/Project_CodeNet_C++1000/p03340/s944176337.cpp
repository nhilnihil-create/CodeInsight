#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans = 0;

  int right = 0;
  int sum = 0;
  for (int left = 0; left < n; left++) {
    while(right < n && (sum ^ a[right]) == (sum + a[right])) {
      sum += a[right];
      right++;
    }

    ans += (right - left);
    if(right == left) right++;
    else sum -= a[left];
  }
  cout << ans << endl;
}