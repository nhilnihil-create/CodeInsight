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

    string s;
    int tx, ty, sx, sy;
    V x, y;

    cin >> s >> tx >> ty;

    bool isX = true;
    int i = 0;

    sx = 0;
    sy = 0;

    while (i < s.size())
    {
        if (s[i] == 'T')
        {
            isX = !isX;
            i++;
            continue;
        }

        int cnt = 0;

        while (i < s.size() && s[i] == 'F')
            cnt++, i++;

        if (cnt == 0)
            continue;

        if (isX)
        {
            x.push_back(cnt);
            sx += cnt;
        }
        else
        {
            y.push_back(cnt);
            sy += cnt;
        }
    }

    if (x.size() && s[0] == 'F')
    {
        tx -= x[0];
        sx -= x[0];

        x[0] = 0;
    }

    if (sx < abs(tx) || sy < abs(ty))
    {
        cout << "No" << endl;
        return 0;
    }

    if ((sx - abs(tx)) % 2 != 0 || (sy - abs(ty)) % 2 != 0)
    {
        cout << "No" << endl;
        return 0;
    }

    bool dpx[8010] = {false};
    bool dpy[8010] = {false};

    dpx[0] = true;
    dpy[0] = true;

    for (int i = 1; i <= (sx - abs(tx)) / 2; i++)
    {
        for (int j = 0; j < x.size(); j++)
        {
            if (i - x[j] >= 0)
                dpx[i] |= dpx[i - x[j]];
        }
    }

    for (int i = 1; i <= (sy - abs(ty)) / 2; i++)
    {
        for (int j = 0; j < y.size(); j++)
        {
            if (i - y[j] >= 0)
                dpy[i] |= dpy[i - y[j]];
        }
    }

    if (dpx[(sx - abs(tx)) / 2] && dpy[(sy - abs(ty)) / 2])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}