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

int main()
{
    ll A, B, K;
    cin >> A >> B >> K;

    ll cnt = 0;
    ll ans = 0;
    vector<ll> SEISU;
    for (ll i = 1; i <= 100; i++)
    {
        if (A % i == 0 && B % i == 0) {
            SEISU.push_back(i);
        }
    }

    sort(SEISU.begin(), SEISU.end(), greater<ll>());
    cout << SEISU[K - 1] << endl;
}