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

struct Fish
{
    ll beauty;
    ll taste;
};

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
    string S;
    cin >> S;

    ll ans = 753;
    for (ll i = 0; i < S.size() - 2; i++)
    {
        string s = S.substr(i, 3);
        ll n = stoi(s);
        if (ans > abs(753 - n)) {
            ans = abs(753 - n);
        }
    }
    cout << ans << endl;
}