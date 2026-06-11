#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const long double EPS = 1e-10;
map<ll, long double> mp;
ll K;
vector<ll> v;

ll digitLen(ll n) {
  ll res = 0;
  while (n) {
    res++;
    n /= 10;
  }
  return res;
}

ll digitSum(ll n) {
  ll res = 0;
  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

long double calc(ll n) {
  if (mp.find(n) != mp.end()) return mp[n];
  return mp[n] = (long double)n / digitSum(n);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> K;
  for (int i = 1; i < 1000; i++) {
    ll tmp = i;
    while (digitLen(tmp) <= 15) {
      v.emplace_back(tmp);
      tmp = tmp * 10 + 9;
    }
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  sort(v.begin(), v.end(), [&](ll a, ll b) {
    long double ca = calc(a);
    long double cb = calc(b);
    if (ca - cb < -EPS) return true;
    if (ca - cb > EPS) return false;
    return a < b;
  });
  ll mx = -1, cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] < mx) continue;
    cout << v[i] << endl;
    mx = v[i];
    cnt++;
    if (cnt == K) break;
  }

  return 0;
}