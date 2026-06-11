#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 5e3 + 5;

int N, A, B, p[maxn];
ll f[maxn];

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  #endif // LOCAL
  cin >> N >> A >> B;
  for(int i = 1; i <= N; ++i)
    cin >> p[i];
  p[N + 1] = N + 1;
  for(int i = 1; i <= N + 1; ++i){
    int le = 0, ri = 0;
    f[i] = 1e18;
    for(int j = i - 1; j >= 0; --j){
      if(p[j] < p[i]) f[i] = min(f[i], f[j] + 1ll * B * le + 1ll * A * ri);
      le += p[j] < p[i], ri += p[j] > p[i];
    }
  }
  cout << f[N + 1];
}
