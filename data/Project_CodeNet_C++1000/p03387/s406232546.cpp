#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector<int> num(3);
  cin >> num[0] >> num[1] >> num[2];
  sort(num.begin(), num.end());
  int ans = 0;
  while (num[1]-num[0] > 1) {
    num[0] += 2;
    ans++;
  }
  if (num[1]-num[0] == 0) ans += num[2]-num[1];
  else ans += num[2]-num[0]+1;
  cout << ans << endl;
}
