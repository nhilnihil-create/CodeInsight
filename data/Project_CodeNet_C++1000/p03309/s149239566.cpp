#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using P = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i] -= i + 1;
  }
  sort(a.begin(), a.end());
  ll mi = INF;

  ll total = 0;
  rep(j, n) { total += abs(a[j] - a[n / 2]); }
  cout << total << endl;
}