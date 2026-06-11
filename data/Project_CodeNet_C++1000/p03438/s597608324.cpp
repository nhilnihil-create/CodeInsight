#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;
#define pow10(n) int(1e##n + n)

void solve()
{
    int N;
    cin >> N;

    vector<LL> a(N);
    LL sum_a = 0;
    REP0 (i, N)
    {
        cin >> a[i];
        sum_a += a[i];
    }

    vector<LL> b(N);
    LL sum_b = 0;
    REP0 (i, N)
    {
        cin >> b[i];
        sum_b += b[i];
    }

    LL op_max = sum_b - sum_a;
    LL ops = 0;
    REP0 (i, N)
    {
        if (a[i] < b[i])
        {
            ops += (b[i] - a[i] + 1) / 2;
        }
    }

    cout << (op_max >= ops ? "Yes" : "No") << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
