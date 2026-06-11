//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define trav(x,a) for (const auto& x: a)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), x.end()
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int _i = 0; _i < (n); _i++) ni(a[_i])
#define nal(a, n) for (int _i = 0; _i < (n); _i++) nl(a[_i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int N = 1e6 + 5;
const double eps = 1e-9;
int a[N], b[N];

int main() {
  int n; ni(n);
  for (int i = 1; i <= n; i++)
      ni(a[i]);
  for (int i = 1; i <= n; i++)
    ni(b[i]);
  int ans = 0;
  for (int i = 28; i >= 0; i--) {
    int c1 = 0, c2 = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] & (1 << i))
        c1++;
      if (b[j] & (1 << i))
        c2++;
      a[j] %= 1 << i;
      b[j] %= 1 << i;
    }
    sort(a+1, a+n+1); sort(b+1, b+n+1);
    int r = n;
    ll tmp = c1 * (n - c2) + c2 * (n - c1);
    for (int j = 1; j <= n; j++) {
      while (r > 0 && a[j]+b[r] >= (1 << i))
        r--;
      tmp += n-r;
    }
    if (tmp & 1)
      ans |= 1 << i;
  }
  printf("%d\n", ans);
  return 0;
}
