#include <bits/stdc++.h>
#define REP(i, n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
using ll = long long;
using namespace std;

int main()
{
    ll N, P;
    cin >> N >> P;

    ll retv = 1;
    ll temp = P;
    ll maxv = powl(P, 1.0/(double)N)+1;
    for (ll i=maxv; i>=2 && temp>=8; --i)
    {
        ll p = powl(i, N);
        if (temp % p != 0) continue;
        temp /= p;
        retv *= i;
    }

    cout << retv << endl;

    return 0;
}
