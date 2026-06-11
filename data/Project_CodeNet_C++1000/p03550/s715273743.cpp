#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef tree< ll, null_type, less< ll >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
  ios_base::sync_with_stdio(false);
  cout.tie(0);cin.tie(0);

  ll n, z, w;
  cin >> n >> z >> w;
  vector < ll > a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  ll ans = abs(w - a[n]);
  if(n > 1) ans = max(ans, abs(a[n] - a[n - 1]));

  cout << ans << '\n';
}
