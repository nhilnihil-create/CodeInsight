#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int pow_100(int d)
{
    int res = 1;

    rep(_, d) res *= 100;
    return res;
}

int main()
{
    int d, n;
    cin >> d >> n;

    cout << ((n == 100) ? pow_100(d) * (n + 1) : pow_100(d) * n) << '\n';
    return (0);
}
