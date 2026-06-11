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

    int n, l[112345], r[112345];

    cin >> n;
    REP(i, n)
    cin >> l[i] >> r[i];

    vector<P> vl, vr;

    REP(i, n)
    {
        vl.push_back({l[i], i});
        vr.push_back({r[i], i});
    }

    SORT(vl);
    SORT(vr);

    reverse(vl.begin(), vl.end());

    ll res = 0;

    ll tmp = 0;

    REP(i, n)
    {
        tmp += vl[i].first;
        res = max(tmp, res);
        tmp += -vr[i].first;
        res = max(tmp, res);
    }

    tmp = 0;

    REP(i, n)
    {
        tmp += -vr[i].first;
        res = max(tmp, res);
        tmp += vl[i].first;
        res = max(tmp, res);
    }

    cout << res * 2 << endl;

    return 0;
}