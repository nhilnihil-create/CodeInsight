#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int d, n;
  cin >> d >> n;
  if (n == 100) n = 101;
  if (d == 0) {
    cout << n;
    return 0;
  }
  if (d == 1) {
    cout << n * 100;
    return 0;
  }
  if (d == 2) {
    cout << n * 10000;
    return 0;
  }
}
