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

int isvacant(int i)
{
    std::cout << i << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if (s[0] == 'V')
    {
        exit(0);
    }
    else if (s[0] == 'F')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void solve()
{
    int N;
    cin >> N;
    int l = 0, r = N - 1;

    int sl = isvacant(l);
    int sr = isvacant(r);

    while (true)
    {
        int m = (l + r) >> 1;
        int sm = isvacant(m);
        if ((sm == sl) != (l % 2 == m % 2))
        {
            r = m;
            sr = sm;
        }
        else
        {
            l = m;
            sl = sm;
        }
    }
}

int main(int argc, char const *argv[])
{
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    // std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
