#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, v) for (auto &&i : v)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define INF 2e9
#define MOD (1000000007)
#define EPS 1e-9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long long int lli;
vector<vector<int>> graph;
vector<bool> visited;
vector<vector<int>> visitedList;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, A, B;
    cin >> N >> A >> B;
    cout << min(A, B) << " " << max(0, A + B - N) << "\n";
}