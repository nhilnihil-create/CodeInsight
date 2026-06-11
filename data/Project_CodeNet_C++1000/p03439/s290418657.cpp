#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;
pair<ll, ll> ps[1 << 20];

int main(void) {

  int n;
  cin >> n;
  n--;
  int d = 0;
  while (n >= 1 << d) d++;
  d--;

  string s, t;
  cout << 0 << endl;
  cin >> s;
  if (s == "Vacant") return 0;

  int l = 0, r = n + 1;
  while (true) {
    int med = (l + r) >> 1;
    cout << med << endl;
    cin >> t;
    if (t == "Vacant") return 0;
    if ((med % 2 == 0 && t == s) || (med % 2 == 1 && t != s)) l = med;
    else r = med;
  }
  return 0;
}
