#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << ": " << x << '\n'

typedef long long int ll;
typedef pair<int, int> P;

const long long INF = 3e18 + 12;
const int inf = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  ll res = 0;
  bool flag = 0;
  rep(i, inf + 1) {
    if (n < i * i) {
      break;
    } else if (n == i * i) {
      flag = 1;
    }
    res = i * i;
  }

  cout << (flag ? n : res) << endl;

  return 0;
}