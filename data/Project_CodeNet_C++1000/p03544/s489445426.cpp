#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  vector<ll> l(87);
  l[0] = 2;
  l[1] = 1;
  for (int i = 2; i < l.size(); i++) {
    l[i] = l[i - 1] + l[i - 2];
  }

  int n;
  cin >> n;
  cout << l[n] << endl;
  return 0;
}