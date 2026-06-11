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
const int MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<string> s(N);
    vector<ll> num(5);
    string x = "MARCH";
    rep(0, i, N)
    {
        cin >> s.at(i);
        rep(0, j, 5)
        {
            if (s.at(i).at(0) == x.at(j))
            {
                num.at(j)++;
            }
        }
    }

    ll ans = 0;
    rep(0, i, 5)
    {
        rep(i + 1, j, 5)
        {
            rep(j + 1, k, 5)
            {
                ans += num.at(i) * num.at(j) * num.at(k);
            }
        }
    }

    cout << ans << endl;
}