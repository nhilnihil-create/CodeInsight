#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 998244353;

int main()
{
    ll N;
    cin >> N;
    map<ll, ll> mp;

    ll a;
    rep(0, i, N)
    {
        cin >> a;
        mp[a]++;
    }

    ll ans = 0;
    for (auto m : mp)
    {
        if (m.first <= m.second)
        {
            ans += m.second - m.first;
        }
        else
        {
            ans += m.second;
        }
    }

    cout << ans << endl;
}