#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a, v;
bitset<4000005> bits[2];

long long solve();

int main() {
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  cout << solve() << endl;
  return 0;
}

long long solve() {
  bits[0][0] = 1;
  for(int i = 0; i < n; ++i)
    bits[(i + 1) % 2] = bits[i % 2] | (bits[i % 2] << a[i]);

  for(int i = 0; i < 4000001; ++i)
    if(bits[n % 2][i]) v.push_back(i);
  return *(
      lower_bound(v.begin(), v.end(), (v.back() + 1) / 2));
}
