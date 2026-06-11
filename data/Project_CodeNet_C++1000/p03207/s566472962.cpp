#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int n;
  cin >> n;
  int mx = 0;
  int sum = 0;
  int t;
  rep(i, n) {
    cin >> t;
    sum += t;
    mx = max(mx, t);
  }
  sum -= mx / 2;
  cout << sum;
}