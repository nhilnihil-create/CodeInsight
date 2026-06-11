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
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

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
    ll N;
    cin >> N;
    vector<ll> a(N), l(N), r(N);
    rep(0, i, N)
    {
        cin >> a.at(i);
        if (i == 0)
        {
            l.at(i) = a.at(i);
        }
        else
        {
            l.at(i) = gcd(l.at(i - 1), a.at(i));
        }
    }
    for (ll i = N - 1; i >= 0; i--)
    {
        if (i == N - 1)
        {
            r.at(i) = a.at(i);
        }
        else
        {
            r.at(i) = gcd(r.at(i + 1), a.at(i));
        }
    }

    ll ans = 1;
    rep(1, i, N - 1)
    {
        ans = max(ans, gcd(l.at(i - 1), r.at(i + 1)));
    }
    ans = max(ans, l.at(N - 2));
    ans = max(ans, r.at(1));
    cout << ans << endl;
}