#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  map<int, int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  int ans = 0;
  for (auto i = a.begin(); i != a.end(); i++) {
    if ((*i).first <= (*i).second)
      ans += (*i).second - (*i).first;
    else
      ans += (*i).second;
  }
  cout << ans << endl;
  return 0;
}