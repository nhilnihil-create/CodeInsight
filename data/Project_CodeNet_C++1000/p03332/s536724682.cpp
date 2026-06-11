#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define BIT(n) (1LL << (n))
#define INF 2e9
#define MOD (998244353)
#define EPS 1e-9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long long int lli;
#define MAXN 300100
#define MAXP 100
/*
lli C[MAXN + 1][MAXP + 1];
void init()
{
    REP(i, MAXN + 1)
    {
        C[i][0] = 1;
    }
    REPS(i, MAXN)
    {
        REPS(j, MAXP)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
} */
lli extGcd(lli a, lli b, lli &x, lli &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        lli d = extGcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}
lli Fact[MAXN + 1];
lli FactInv[MAXN + 1];
void initG()
{
    vector<lli> invN(MAXN + 1);
    REPS(i, MAXN)
    {
        lli x, y;
        extGcd(i, MOD, x, y);
        x %= MOD;
        x = (x + MOD) % MOD;
        invN[i] = x;
    }
    Fact[0] = 1;
    FactInv[0] = 1;
    REPS(i, MAXN)
    {
        Fact[i] = (Fact[i - 1] * i) % MOD;
        FactInv[i] = (FactInv[i - 1] * invN[i]) % MOD;
    }
}
int main()
{
    initG();

    cin.tie(0);
    ios::sync_with_stdio(false);
    lli N, A, B, K;
    cin >> N >> A >> B >> K;
    // init();
    //   Ax + By = K x >= 0, y >= 0となるものを考える。
    lli x, y;
    lli d = extGcd(A, B, x, y);
    if (K % d != 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        //   cout << d << "\n";
        A /= d;
        B /= d;
        K /= d;
        lli savey = y;
        x *= K;
        x %= B;
        x += B;
        x %= B;
        y = (K - A * x) / B;
        lli xa = x, ya = y;
        // x min +B -A
        // x=10,y=6,N=22  -> 10 6 0 6,9 5 1 7,8 4 2 8
        //cout << x << " " << y << "\n";
        y = savey * K;
        y %= A;
        y += A;
        y %= A;
        x = (K - B * y) / A;
        // y min
        lli xb = x;

        //cout << x << " " << y << "\n";
        lli i = xa;
        lli j = ya;
        lli ans = 0;
        if (j > N)
        {
            lli tmp = (j - (N + 1)) / A + 1;
            i += tmp * B;
            j -= tmp * A;
        }
        for (; i <= min(xb, N); i += B)
        {
            //      cout << i << " " << j << " "
            //          << "\n";
            lli tmp = (Fact[N] * Fact[N]) % MOD;
            tmp *= FactInv[i];
            tmp %= MOD;
            tmp *= FactInv[N - i];
            tmp %= MOD;
            tmp *= FactInv[j];
            tmp %= MOD;
            tmp *= FactInv[N - j];
            tmp %= MOD;
            ans += tmp;
            ans %= MOD;
            j -= A;
        }
        cout << ans << "\n";
    }
}
