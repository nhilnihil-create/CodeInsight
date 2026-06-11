#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> as(n), bs(n);
  for (auto &a : as)
    cin >> a;
  for (auto &b : bs)
    cin >> b;

  ll asum = accumulate(as.begin(), as.end(), 0LL);
  ll bsum = accumulate(bs.begin(), bs.end(), 0LL);

  ll cnt = 0;
  for (int i = 0; i < n; ++i)
    cnt += max((bs[i] - as[i] + 1) / 2, 0LL);

  if (cnt <= bsum - asum)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
