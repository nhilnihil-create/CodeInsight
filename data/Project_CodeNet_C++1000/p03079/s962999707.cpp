#include <bits/stdc++.h>

using namespace std;
long long x[10000010], y[10000010];
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i < (n)i++)
#define all(x) (x).begin(), (x).end()
#define rv(s) reverse((s).begin(), (s).end())
#define pii pair<int, int>
#define int long long
#define setout(n, x) setw(n) << setfill(x)
#define Fixed fixed << setprecision(10);
const long long mod = 1e9 + 7;

signed main()
{

   cin.tie(0);
   ios::sync_with_stdio(false);

   int a, b, c;
   cin >> a >> b >> c;

   if (a == b && a == c)
      cout << "Yes" << '\n';
   else
      cout << "No" << '\n';
}