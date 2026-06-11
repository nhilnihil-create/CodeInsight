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

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr double PI = 3.14159265358979323846;
constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll c, x[112345], v[112345];

    cin >> n >> c;
    REP(i, n)
    cin >> x[i + 1] >> v[i + 1];

    x[0] = 0;
    x[n + 1] = c;
    v[0] = 0;
    v[n + 1] = 0;

    ll sumR[112345], mxR[112345], sumL[112345], mxL[112345];

    ll res = 0;

    sumR[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sumR[i] = sumR[i - 1] + v[i];
    }

    mxR[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sumR[i] -= x[i];
        mxR[i] = max(mxR[i - 1], sumR[i]);
    }

    sumL[n + 1] = 0;
    for (int i = n; i > 0; i--)
    {
        sumL[i] = sumL[i + 1] + v[i];
    }

    mxL[n + 1] = 0;
    for (int i = n; i > 0; i--)
    {
        sumL[i] -= c - x[i];
        mxL[i] = max(mxL[i + 1], sumL[i]);
    }

    for (int i = 0; i <= n; i++)
        res = max(res, sumR[i] + mxL[i + 1] - x[i]);

    for (int i = n + 1; i > 0; i--)
        res = max(res, sumL[i] + mxR[i - 1] - (c - x[i]));

    cout << res << endl;

    return 0;
}