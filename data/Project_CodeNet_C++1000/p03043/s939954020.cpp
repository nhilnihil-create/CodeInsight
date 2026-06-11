#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    double n, k;
    cin >> n >> k;
    double res = 0;
    rep(i, n)
    {
        double now = 1.0 / n;
        ll pp = i + 1;
        while (pp < k)
        {
            pp *= 2;
            now /= 2.0;
        }
        res += now;
    }
    cout << setprecision(15) << res << endl;

    return 0;
}