#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

/*
using PAIR = pair<string, int>;
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long ll;

#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define debug_() cerr << "AAAAA" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;

using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<vector<int>> a(c, vector<int>(c));
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
            b[i][j] -= 1;
        }
    }
    vector<vector<ll>> SUM(3, vector<ll>(c, 0));
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                SUM[(j + k) % 3][i] += a[b[j][k]][i];
            }
        }
    }
    // debug_();

    ll ans = 1001001001001001;
    for (int p = 0; p < c; p++)
    {
        for (int q = 0; q < c; q++)
        {
            if (p == q)
                continue;
            for (int r = 0; r < c; r++)
            {
                if (r == p || r == q)
                    continue;
                ll tmp = SUM[0][p] + SUM[1][q] + SUM[2][r];
                ans = min(ans, tmp);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
