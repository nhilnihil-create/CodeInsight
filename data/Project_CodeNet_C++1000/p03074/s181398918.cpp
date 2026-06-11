#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
 
using namespace std;
using namespace __gnu_pbds;
 
#define debug(s) cout << #s << " = " << s << endl
#define all(v) (v).begin(), (v).end()
#define mem(a,val) memset(a, val, sizeof a)
 
#define maxn 100010
#define INF 1e15
#define ff first
#define ss second
#define endl '\n'
typedef long long ll;
 
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n, k;
int cum[maxn], sum[maxn];
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  cin >> s;
  vector<int> v;
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      v.push_back(cnt);
      if (s[i - 1] == '0') cum[(int)v.size()] = 1;
      cnt = 1;
    }
    else cnt++;
  }
  v.push_back(cnt);
  if (s[n - 1] == '0') cum[(int)v.size()] = 1;
  n = v.size();
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + v[i - 1];
  for (int i = 1; i <= n; ++i) cum[i] += cum[i - 1];
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int lo = 0, hi = n - i - 1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (cum[mid + i + 1] - cum[i] <= k) {
        ans = max(ans, sum[mid + i + 1] - sum[i]);
        lo = mid + 1;
      }
      else hi = mid - 1;
    }
  }
  cout << ans << endl;
}



