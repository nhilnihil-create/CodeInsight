#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int findDigits(int n) {
  int cnt = 0;
  int kaibun[5];
  rep(i, 5) {
    kaibun[i] = n % 10;
    n /= 10;
  }
  if (kaibun[0] == kaibun[4] && kaibun[1] == kaibun[3]) cnt++;

  return cnt;
}

int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;

  for (int i = a; i <= b; i++) {
    ans += findDigits(i);
  }
  cout << ans << endl;

  return 0;
}