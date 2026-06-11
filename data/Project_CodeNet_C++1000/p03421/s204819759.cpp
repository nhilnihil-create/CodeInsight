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
    int n, a, b;

    cin >> n >> a >> b;

    if (a + b - 1 > n)
    {
        cout << -1 << endl;
        return 0;
    }

    if ((ll)a * b < n)
    {
        cout << -1 << endl;
        return 0;
    }

    V res;

    int ma = n;

    for (int i = ma - a + 1; i <= ma; i++)
        res.push_back(i);

    ma = n - a;

    b--;

    for (int i = b; i > 0; i--)
    {
        int t = ma / i;

        for (int j = ma - t + 1; j <= ma; j++)
            res.push_back(j);

        ma -= t;
    }

    REP(i, n)
    cout << res[i] << (i == n - 1 ? "\n" : " ");

    return 0;
}