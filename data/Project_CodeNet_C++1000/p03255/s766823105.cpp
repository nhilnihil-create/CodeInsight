#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

lint N, X;
vector<lint> x;
constexpr lint Nmax = 200000;
constexpr lint INF = 10000000000000000;
inline lint calc(lint Y) // Y個のグループにわけるときの値を算出
{
    lint ans = X * (N + Y);
    REP(i, N)
    {
        if (ans >= INF) return INF;
        lint d = i / Y;
        if (d)
            ans += x[i] * (2 * d + 3);
        else
            ans += x[i] * 5;
        
    }
    return ans;
}

int main()
{
    cin >> N >> X;
    x.resize(N);
    REP(i, N) cin >> x[i];

    reverse(x.begin(), x.end());

    lint l = 0, r = N + 1;
    while (l + 2 < r)
    {
        lint left = (l * 2 + r) / 3;
        lint right = (l + r * 2) / 3;

        // cerr << l << " " << left << " " << right << " " << r << endl;
        if (calc(left) < calc(right)) r = right;
        else l = left;
    }
    cout << calc((l + r) / 2) << endl;
}
