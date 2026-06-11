#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define REP(i, N) for (int i = 0; i < N; i++)
#define REP1(i, N) for (int i = 1; i < N; i++)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ANS(a) cout << a << endl
#define SORT(V) sort(V.begin(), V.end())
#define RSORT(V) sort(V.rbegin(), V.rend())
#define DBG(V) for (auto v : V) cout << v << " "; cout << endl

int N;
vector<int> P;

int
main()
{
  cin >> N;
  REP(i, N) { int p; cin >> p; P.push_back(p); }

  RSORT(P);
  int ans = P[0] / 2;
  REP1(i, N) { ans += P[i]; }

  cout << ans << endl;
}
