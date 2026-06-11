#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
const ll MAX = 2*(ll)pow(10, 5);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll a, b; cin >> a >> b;
  bool flag = 1;
  if (a%2==0 || b%2==0) flag = 0;
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}