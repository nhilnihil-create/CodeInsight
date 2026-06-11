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

ll f(ll n) {
    if (n % 2 == 0) {
        return n /2;
    } else {
        return 3 * n + 1;
    }
}
int main()
{
    ll s;
    cin >> s;

    ll cur = s;
    vector<ll> vec;
    vec.push_back(cur);

    map<ll, ll> mp;

    for (ll i = 2; i < 1000000; i++)
    {
        cur = f(cur);
        vec.push_back(cur);
        mp[cur] += 1;
    }

    ll ans = 0;
    for (ll i = 0; i < 1000000; i++)
    {
        if (mp[vec[i]] > 1) {
            ans = vec[i];
            break;
        }
    }

    ll res = 0;
    for (ll i = 0; i < 1000000; i++)
    {
        if (vec[i] == ans && res == 1) {
            cout << (i + 1) << endl;
            return 0;
        }
        if (vec[i] == ans) {
            res += 1;
        }
    }
}
