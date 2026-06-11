#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define mp make_pair
#define fi first
#define se second
#define pb push_back

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

    int n, k, q, a[2010];

    V v;

    cin >> n >> k >> q;

    REP(i, n)
    cin >> a[i], v.push_back(a[i]);

    a[n] = -1;

    SORT(v);

    int res = INT_MAX;

    int j = 0;

    while (true)
    {
        V x;
        int l = 0;
        int r = 0;
        while (r <= n)
        {
            if (a[r] == -1)
            {
                if (r - l >= k)
                {
                    priority_queue<int, vector<int>, greater<int>> q;
                    for (int i = l; i < r; i++)
                        q.push(a[i]);

                    for (int i = r - l; i >= k; i--)
                    {
                        x.push_back(q.top());
                        q.pop();
                    }
                }
                l = r + 1;
            }

            r++;
        }

        SORT(x);

        if (x.size() < q)
            break;

        res = min(res, x[q - 1] - x[0]);

        for (int i = 0; i < n; i++)
            if (a[i] == v[j])
                a[i] = -1;
        j++;
    }

    cout << res << endl;

    return 0;
}