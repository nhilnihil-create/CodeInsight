#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    int cnt = 0;
    while (tmp % 2 == 0) {
      cnt++;
      tmp /= 2;
    }
    ans += cnt;
  }
  cout << ans << endl;
}
