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
    vector<ll> goods(N);
    ll sum = 0;
    for (ll i = 0; i < N; i++)
    {
        cin >> goods[i];
        sum += goods[i];
    }
    
    sort(goods.begin(), goods.end());
    cout << (sum - goods[N - 1] / 2) << endl;
}