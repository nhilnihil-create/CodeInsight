#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define ll long long
using namespace std;
const int MOD = 1000000007;
const long long INF = 1LL << 60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<string> s(n);
  map<char, ll> mp;
  ll cnt;
  for (ll i = 0; i < n; i++) {
    cin >> s[i];
  }
  int cntab = 0;
  int a = 0;
  int b = 0;
  int ba = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i].front() == 'B') b++;
    if (s[i].back() == 'A') a++;
    if (s[i].front() == 'B' && s[i].back() == 'A') ba++;
    for (int j = 0; j < (int)s[i].size() - 1; ++j) {
      if (s[i][j] == 'A' && s[i][j + 1] == 'B') cntab++;
    }
  }
  cntab += min(a, b);
  if (a > 0 && a == b && a == ba) cntab--;
  cout << cntab << endl;
}