#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e18;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};


int main() {
  ll a,b,c,k;
  cin >> a >> b >> c >> k;

  if (k % 2 == 0) cout << a-b << endl;
  else cout << b-a << endl;

  return 0;
}
