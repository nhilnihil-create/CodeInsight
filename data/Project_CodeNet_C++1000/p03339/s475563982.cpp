#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
 
using namespace std;
using namespace __gnu_pbds;
 
#define debug(s) cout << #s << " = " << s << endl
#define all(v) (v).begin(), (v).end()
#define mem(a,val) memset(a, val, sizeof a)
 
#define maxn 300010
#define INF 1e15
#define ff first
#define ss second
#define endl '\n'
typedef long long ll;
 
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int wl[maxn];
int wr[maxn];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == 'W') wl[i] = wl[i - 1] + 1;
    else wl[i] = wl[i - 1];
  }
  for (int i = n; i >= 1; --i) {
    if (s[i - 1] == 'E') wr[i] = wr[i + 1] + 1;
    else wr[i] = wr[i + 1];
  }
  int ans = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    ans = min(ans, wl[i - 1] + wr[i + 1]);
  }
  cout << ans << endl;
}



