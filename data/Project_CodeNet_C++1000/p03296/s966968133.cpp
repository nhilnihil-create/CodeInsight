#include <bits/stdc++.h>

using namespace std;
#define int int64_t
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) (x).begin(), (x).end()
#define gsort(x) sort((x).begin(), (x).end(), greater<int>())
#define rv(s) reverse((s).begin(), (s).end())
#define pii pair<int, int>
#define re(s) reverse((s).begin(), (s).end())
#define setout(n, x) setw(n) << setfill(x)
#define Fixed fixed << setprecision(10);
#define pb(x, a) (x).push_back(a)
#define fb(x, a) (x).flont_back(a)
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const long long mod = 1e9 + 7;

signed main()
{
   cin.tie(0);
   ios::sync_with_stdio(false);

   int n, cnt = 0;
   cin >> n;
   vector<int> x;
   x.resize(n);

   rep(i, n)
   {
      cin >> x[i];
   }

   reps(i, n - 1)
   {
      if (x[i] == x[i - 1])
      {
         ++cnt;
         x[i] = 0;
      }
   }

   cout << cnt << '\n';
}