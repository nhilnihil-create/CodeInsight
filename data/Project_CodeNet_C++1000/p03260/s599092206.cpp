#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    ll a, b;
    cin >> a >> b;
    if (a * b % 2 == 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}
