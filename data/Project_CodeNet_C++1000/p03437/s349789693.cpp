#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int x,y;
  cin>>x>>y;
  if (x == y || x % y == 0) {
    cout << -1;
    return 0;
  }
  for (ull i = x; i <= 1000000000000000000; i += x) {
    if (i % y != 0) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
