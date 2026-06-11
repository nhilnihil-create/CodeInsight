#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {ll k, a, b;cin >> k >> a >> b;if(b - a <= 2 || a - 1 > k){cout << 1 + k << endl;return 0;}k -= a - 1;ll count = a;ll n = floor(k / 2);rep(i, n) count += b - a;if(k % 2 == 1) count++;cout << count << endl;}