#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

using tl = tuple<ll, ll, ll>;

istream& operator>>(istream& in, tl& t)
{
    ll p,q,r;
    cin >> p >> q >> r;
    t = tl{p,q,r};
    return cin;
}

int n, m;
tl a[1000];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll sol = 0;
    for (int i = 0; i < (1 << 3); ++i)
    {
        ll cst[1000];
        for (int j = 0; j < n; ++j)
        {
            ll p,q,r;
            tie(p,q,r) = a[j];
            if (i & 1)
                p *= -1;
            if (i & 2)
                q *= -1;
            if (i & 4)
                r *= -1;
            cst[j] = p + q + r;
        }
        sort(cst, cst + n);
        reverse(cst, cst + n);
        ll sum = 0;
        for (int j = 0; j < m; ++j)
            sum += cst[j];
        sol = max(sol, sum);
    }
    cout << sol;
}
