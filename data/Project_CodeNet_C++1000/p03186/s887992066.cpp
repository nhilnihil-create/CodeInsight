#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  Long a, b, c;
  cin >> a >> b >> c;

  Long res = b;
  res += min(c, a + b + 1);

  cout << res << endl;
}

