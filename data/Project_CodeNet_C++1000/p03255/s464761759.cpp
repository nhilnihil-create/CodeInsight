#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
#define inf 999999999
#define loop(i, a, b) for (int i = (a), i##len = (b); i < i##len; ++i)
#define rep(i, n) loop(i, 0, n)
#define lin long long
#define lfl long double
typedef boost::multiprecision::cpp_int bigint;

lin n, x[200011], xx, tx[200011];

lin sum(lin ed)
{
    return tx[ed+1];
}

bigint solve(lin i)
{
    lin idx = n - 1;
    bigint res = 5 * sum(idx) + (i + n) * xx;
    
    idx -= i * 2;

    while(idx >= 0)
    {
        res += (bigint)(2 * sum(idx));
        idx -= i;
    }

    return res;
}

int main(void)
{
    cin >> n >> xx;
    //n = 200000;
    //xx = 1000000000;

    tx[0] = 0;
    rep(i,n)
    {
        cin >> x[i];
        //x[i] = i + 1000000000 - 200000;
        tx[i+1] = tx[i] + x[i];
    }

    auto res = solve(1);

    for(int i = 2; i <= n; i++)
    {
        res = min(res, solve(i));
    }

    cout << res << endl;

    return 0;
}
