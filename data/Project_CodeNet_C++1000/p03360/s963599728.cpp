#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  vector<ll> num(3);
  ll K;
  cin >> num[0] >> num[1] >> num[2] >> K;

  sort(num.rbegin(), num.rend());

  rep(i, K) {
    num[0] = num[0] * 2;
  }

  cout << num[0] + num[1] + num[2] << endl;
  
  return 0;
}