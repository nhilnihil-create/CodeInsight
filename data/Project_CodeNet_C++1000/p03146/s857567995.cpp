#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int f(int n) {
  if (n % 2) n = n * 3 + 1;
  else n = n / 2;
  return n;
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int s; cin >> s;
  map<int, int> m;
  int i = 1;
  while (!m[s]) {
    m[s] = 1;
    s = f(s);
    i++;
  }
  cout << i << '\n';
}
