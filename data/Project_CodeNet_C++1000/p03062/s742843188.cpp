#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n, mi = MOD, m = 0;
    cin >> n;
    ll sum = 0;
    rep(i, n)
    {
        int a;
        cin >> a;
        sum += abs(a);
        if (a < 0)
            m++;
        mi = min(mi, abs(a));
    }
    if (m % 2 == 0)
        cout << sum << endl;
    else
        cout << sum - 2 * mi << endl;
}