#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define INF 2e9
#define MOD (1000000007)
#define EPS 1e-9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long long int lli;
lli gcd(lli m, lli n)
{
    return (m % n == 0) ? n : gcd(n, m % n);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    lli T, A, B, C, D;
    cin >> T;
    REP(i, T)
    {
        cin >> A >> B >> C >> D;
        if (A < B || D < B)
        {
            cout << "No"
                 << "\n";
        }
        else
        {
            //            D>=B,A>=B
            if (C >= B - 1)
            {
                cout << "Yes"
                     << "\n";
            }
            else
            {
                lli d = gcd(B, D);
                //C+1とB-1にA%dのやつが存在しないようにする。
                if (B - d + A % d >= C + 1)
                {
                    cout << "No"
                         << "\n";
                }
                else
                {
                    cout << "Yes"
                         << "\n";
                }
            }
        }
    }
}
