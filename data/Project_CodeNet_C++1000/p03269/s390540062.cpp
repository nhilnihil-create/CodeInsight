#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0e-14;
#define pow10(n) int(1e##n + n)

struct edge
{
    LL s, t, l;
};

void solve()
{
    LL L;
    cin >> L;

    vector<edge> G;

    int s = 1;
    while ((1LL << s) <= L)
    {
        G.push_back(edge{s, s + 1, 0});
        G.push_back(edge{s, s + 1, 1LL << (s - 1)});
        s++;
    }

    LL p2 = (1LL << (s - 1));
    LL N = s;

    for (int t = N - 1; t > 0; t--)
    {
        if (p2 + (1LL << (t - 1)) <= L)
        {
            L -= (1LL << (t - 1));
            G.push_back(edge{t, N, L});
        }
    }
    cout << N << " " << G.size() << endl;
    for (auto e : G)
    {
        cout << e.s << " " << e.t << " " << e.l << endl;
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
