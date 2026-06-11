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
    ll N;
    cin >> N;
    map<string, ll> mp;
    vector<string> words(N);

    bool ok = true;

    for (ll i = 0; i < N; i++)
    {
        string w;
        cin >> w;
        
        words[i] = w;
        mp[w] += 1;

        if (i > 0) {
            ok &= words[i - 1].back() == words[i].front();
        }
        if (mp[w] > 1) {
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}