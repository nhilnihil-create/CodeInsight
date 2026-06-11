#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e3 + 5;
const ll llinf = 1e18;

int N, a[maxn];
int K, Q;

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  #endif // LOCAL
  cin >> N >> K >> Q;
  int res = 1e9;
  for(int i = 1; i <= N; ++i){
    cin >> a[i];
  }
  for(int pv = 1; pv <= N; ++pv){
    vector<int> all;
    for(int i = 1; i <= N; ++i){
      if(a[i] < a[pv]) continue;
      int j = i;
      vector<int> v;
      while(j <= N && a[j] >= a[pv]){
        v.pb(a[j]);
        ++j;
      }
      i = j - 1;
      sort(v.rbegin(), v.rend());
      for(int k = K - 1; k < v.size(); ++k)
        all.pb(v[k]);
    }
    sort(all.begin(), all.end());
    if(all.size() >= Q) res = min(res, all[Q - 1] - a[pv]);
    //if(a[pv] == 1) for(auto & it : all) cerr << it << ' ';
  }
  cout << res;
}
