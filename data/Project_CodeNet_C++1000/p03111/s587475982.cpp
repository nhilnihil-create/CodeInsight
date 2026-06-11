#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define pii pair<int, int>
#define Task "abc"
#define For(i, a, b) for(int i = (a), _b = (b); i <= b; ++i)
#define Debug(X) cout << #X << " = " << X << '\n'
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;

const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int n, a, b, c;
int l[8];
int ans = 3e3;

void backtrack(int i, int ca, int cb, int cc, int am, int bm, int cm){
  if (i == n){
    if (am == 0 || bm == 0 || cm == 0) return;
    ans = min(ans, am + abs(ca - a) + bm + abs(cb - b) + cm + abs(cc - c) - 30);
    return;
  }
  backtrack(i + 1, ca, cb, cc, am, bm, cm);
  backtrack(i + 1, ca + l[i], cb, cc, am + 10, bm, cm);
  backtrack(i + 1, ca, cb + l[i], cc, am, bm + 10, cm);
  backtrack(i + 1, ca, cb, cc + l[i], am, bm, cm + 10);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin);
//  freopen(Task".out", "w", stdout);
  cin >> n >> a >> b >> c;
  for (int i = 0; i < n; ++i) cin >> l[i];
  backtrack(0, 0, 0, 0, 0, 0, 0);
  cout << ans;
}

