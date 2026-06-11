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
#define debug_vec2(v)                         \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
        {                                     \
            cout << v[i][j] << " ";           \
        }                                     \
        cout << endl;                         \
    }

using Graph = vector<vector<int>>;
using P = pair<int, int>;
using P1 = pair<int, pair<int, int>>; // クラスカル法とかで、{cost, {from, to}}的に使う。
const int INF = 1001001001;
const double pi = acos(-1);

bool is_prime(ll n)
{
    if (n == 1)
        return false;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int q;
    cin >> q;
    vector<bool> a(100009, false);
    vector<int> SUM(100009, 0);
    for (int i = 1; i < a.size(); i++)
    {
        if (is_prime(i))
        {
            a[i] = true;
            if (a[(i + 1) / 2])
            {
                SUM[i] = SUM[i - 1] + 1;
            }
        }
    }
    for (int i = 0; i < 100007; i++)
    {
        SUM[i + 1] += SUM[i];
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << SUM[r] - SUM[l - 1] << endl;
    }

    return 0;
}
