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
    int n, x;
    cin >> n >> x;
    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    if (n == 1)
    {
        cout << abs(d[0] - x) << endl;
        return 0;
    }
    int ans = __gcd(abs(x - d[0]), abs(x - d[1]));
    for (int i = 0; i < n; i++)
    {
        ans = __gcd(ans, abs(x - d[i]));
    }
    cout << ans << endl;

    return 0;
}
