#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
#define pow10(n) int(1e##n + n)

bool is_prime(long long N)
{
    if (N <= 1)
        return false;
    if (N == 2)
        return true;
    long long ub = std::sqrt(N);
    if (ub * ub == N)
        return false;
    for (long long i = 3; i <= ub; i += 2)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}

vector<LL> divisor(LL n)
{
    vector<LL> ret;
    for (LL i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

// 素因数
int divisors[100];

int num(int k)
{
    int ret = 0;
    REP1 (i, 100)
    {
        if (divisors[i] >= k - 1)
            ret++;
    }
    return ret;
}

void solve()
{
    int N;
    cin >> N;

    for (int i = 2; i <= N; i++)
    {
        int cur = i;
        for (int j = 2; j <= i; j++)
        {
            while (cur % j == 0)
            {
                divisors[j]++;
                cur /= j;
            }
        }
    }

    cout << num(75) + num(25) * (num(3) - 1) + num(15) * (num(5) - 1) + num(5) * (num(5) - 1) * (num(3) - 2) / 2 << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
