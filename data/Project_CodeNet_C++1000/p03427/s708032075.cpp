#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int keta(ll n) { return log10(n) + 1; }

int main() {
  ll n;
  cin >> n;
  n++;
  cout << (keta(n) - 1) * 9 + ll((n / pow(10, keta(n) - 1)) - 1) << endl;
  return 0;
}
