#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <utility>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main()
{
    ll n;
    cin >> n;
    map<ll, ll> v1, v2;
    repi(i, n, 0)
    {
        ll v;
        cin >> v;
        if (i % 2)
        {
            v1[v]++;
        }
        else
        {
            v2[v]++;
        }
    }
    ll m1 = 0, m2 = 0, val1, val2, prev1 = 0, prev2 = 0;
    for (auto itr = v1.begin(); itr != v1.end(); itr++)
    {
        if (m1 < itr->second)
        {
            prev1 = m1;
            val1 = itr->first;
            m1 = itr->second;
        }
        else
        {
            prev1 = max(prev1, itr->second);
        }
    }
    for (auto itr = v2.begin(); itr != v2.end(); itr++)
    {
        if (m2 < itr->second)
        {
            prev2 = m2;
            val2 = itr->first;
            m2 = itr->second;
        }
        else
        {
            prev2 = max(prev2, itr->second);
        }
    }
    if (val1 != val2)
    {
        cout << n - m1 - m2 << endl;
    }
    else
    {
        cout << (prev1 + m2 > prev2 + m1 ? n - prev1 - m2 : n - prev2 - m1) << endl;
    }
    return 0;
}