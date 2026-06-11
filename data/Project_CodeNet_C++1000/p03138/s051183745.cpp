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

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N), c(40);
    rep(0, i, N)
    {
        cin >> a.at(i);
        bitset<40> bit(a.at(i));
        rep(0, j, 40)
        {
            if (bit.test(j))
            {
                c.at(j)++;
            }
        }
    }

    ll x = 0;
    ll ans = 0;
    for (ll i = 39; i >= 0; i--)
    {
        if ((x + ((ll)1 << i) <= K) && (c.at(i) < ((N + 1) / 2)))
        {
            x += (ll)1 << i;
        }
    }

    rep(0, i, N)
    {
        ans += a.at(i) ^ x;
    }

    cout << ans << endl;
}