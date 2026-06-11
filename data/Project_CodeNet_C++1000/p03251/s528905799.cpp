#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <regex>
#include <iomanip>
#include <climits>
#include <utility>
#include <queue>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

ll fact(ll n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1) % MOD;
}

int main()
{
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;

    bool ok = true;
    ll mx_x = X;
    for (ll i = 0; i < N; i++)
    {
        ll xi;
        cin >> xi;
        mx_x = max(mx_x, xi);
    }

    ll mx_y = Y;
    for (ll i = 0; i < M; i++)
    {
        ll yi;
        cin >> yi;
        mx_y = min(mx_y, yi);
    }

    cout << (mx_x < mx_y ? "No War" : "War") << endl;    
}