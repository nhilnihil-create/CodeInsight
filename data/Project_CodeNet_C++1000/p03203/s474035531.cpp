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

    int h, w, n, x[212345], y[212345], mi[212345];

    cin >> h >> w >> n;

    fill(mi, mi + h + 1, w + 1);

    REP(i, n)
    {
        cin >> x[i] >> y[i];

        mi[x[i]] = min(mi[x[i]], y[i]);
    }

    int r = 1;
    for (int i = 2; i <= h; i++)
    {
        if (mi[i] <= r)
        {
            cout << i - 1 << endl;
            return 0;
        }

        r = min(mi[i] - 1, r + 1);
    }

    cout << h << endl;

    return 0;
}