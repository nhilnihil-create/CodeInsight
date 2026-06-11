#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)
#define pow10(n) int(1e##n + n)

typedef long long LL;
typedef pair<int, int> P;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;

template <typename number> number numpow(number a, LL b)
{  // a^b
    if (b == 0)
        return 1;

    if (b % 2 == 0)
    {
        number d = numpow(a, b / 2);
        return (d * d);
    }

    return (a * numpow(a, b - 1));
}

void solve()
{
    LL n, m, d;
    cin >> n >> m >> d;
    double avg_pair = (d >= 1 ? 2 * double(n - d) : double(n)) / double(n * n);
    std::cout << avg_pair * (m - 1) << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
