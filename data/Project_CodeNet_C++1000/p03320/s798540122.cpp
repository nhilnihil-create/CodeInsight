#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get(ll x) {
  ll sum = 0;
  while(x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

ll get_next(ll x) {
  ll possible = x, pw = 1, extra = 0;
  while(x > 0) {
    extra += pw * 9ll;
    pw *= 10ll;
    x /= 10ll;
    if(possible * get(x * pw + extra) > get(possible) * (x * pw + extra)) {
      possible = x * pw + extra;
    }
  }
  return possible;
}

int main() {
  int n; cin >> n;
  ll cur = 1;
  while(n--) {
    cout << cur << '\n';
    cur = get_next(cur + 1);
  }
}
