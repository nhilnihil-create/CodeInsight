#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main()
{
    int n, k;
    cin >> n >> k;

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (n / i) * max(i - k, 0) + max(n % i - k + 1, 0);
    }
    if (k == 0)
        OP(ans - n);
    else
        OP(ans);

    return 0;
}