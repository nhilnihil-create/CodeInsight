#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr ll INF = 1e18;

int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  if (k % 2 != 0) {
    if ( b - a > INF) cout << "Unfair" << endl;
    else cout << b - a << endl;
  } else {
    if (a - b > INF) cout << "Unfair" << endl;
    else cout << a - b << endl;
  }
  return 0;
} 