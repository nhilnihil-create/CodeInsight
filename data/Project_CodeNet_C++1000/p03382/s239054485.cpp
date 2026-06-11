#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e5 + 5;

int sol;
int a[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;

  REP(i, n) cin >> a[i];
  sort(a, a + n);

  int mx = a[n - 1];
  sol = 0;

  REP(i, n) {
    if(abs(a[i] * 2 - mx) < abs(mx - sol * 2)) {
      sol = a[i];
    }
  }

  cout << mx _ sol << endl;
}
