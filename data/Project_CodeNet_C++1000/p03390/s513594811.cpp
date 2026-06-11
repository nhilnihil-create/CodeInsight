#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    ll a[110], b[110];

    cin >> q;

    REP(i, q)
    cin >> a[i] >> b[i];

    REP(i, q)
    {
        ll t = a[i] * b[i];
        t--;

        ll l = 0;
        ll r = LLONG_MAX;

        while (r - l > 1)
        {
            ll mid = (l + r) / 2;

            if (t / mid >= mid)
                l = mid;
            else
                r = mid;
        }

        if (l == 0)
        {
            cout << 0 << endl;
            continue;
        }

        ll res = l * 2;

        if (t / l == l)
            res--;

        if (a[i] <= l)
            res--;

        if (b[i] <= l)
            res--;

        cout << res << endl;
    }

    return 0;
}