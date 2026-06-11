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
#define debugA() cerr << "AAAAA" << endl
#define debug_() cerr << "-------------" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;

using Graph = vector<vector<int>>;

int main()
{
    int m, k;
    cin >> m >> k;
    if (m == 1)
    {
        if (k == 0)
        {
            cout << "0 0 1 1" << endl;
            return 0;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if (pow(2, m) - 1 < k)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = pow(2, m) - 1; i >= 0; i--)
    {
        if (i == k)
        {
            continue;
        }
        cout << i << " ";
    }
    cout << k << " ";
    for (int i = 0; i < pow(2, m); i++)
    {
        if (i == k)
        {
            continue;
        }
        cout << i << " ";
    }
    cout << k << endl;

    return 0;
}
