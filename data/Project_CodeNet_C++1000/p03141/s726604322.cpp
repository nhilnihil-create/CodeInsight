#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define rrep(i, a, n) for (int i = (int)(a); i >= (int)(n); --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debug2(x, y)                       \
  cerr << "(" << #x << "," << #y << ") = " \
       << "(" << x << "," << y << ")\n"
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;
using pii = pair<int, int>;
const int MX = 1e5 + 5, INF = 5LL << 57, MOD = 1e9 + 7;

int N;
int A[MX];
int B[MX];
vector<pii> PAB;

void input()
{
  cin >> N;
  rep(i, 1, N)
  {
    int a, b;
    cin >> a >> b;
    A[i] = a, B[i] = b;
    PAB.emplace_back(a + b, i);
  }
}
void solve()
{
  sort(all(PAB));
  reverse(all(PAB));

  int ans = 0;
  rep(i, 0, N-1)
  {
    if (i&1LL)
    {
      ans -= B[PAB[i].second];
    }
    else
    {
      ans += A[PAB[i].second];
    }
    //debug2(i,ans);
  }

  cout << ans << endl;
}
signed main()
{
  cout << setprecision(12);
  input();
  solve();
  return 0;
}