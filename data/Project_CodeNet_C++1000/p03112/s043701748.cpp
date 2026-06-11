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
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a + 2);
    vector<ll> t(b + 2);
    s[0] = -100100100100;
    t[0] = -100100100100;
    s[a + 1] = 1001001001001;
    t[b + 1] = 1001001001001;
    for (int i = 0; i < a; i++)
    {
        cin >> s[i + 1];
    }
    for (int i = 0; i < b; i++)
    {
        cin >> t[i + 1];
    }
    // debug_vec(s);
    // debug_vec(t);

    for (int i = 0; i < q; i++)
    {
        ll x;
        cin >> x;
        auto u = lower_bound(s.begin(), s.end(), x);
        auto v = lower_bound(t.begin(), t.end(), *u);
        auto w = u - 1;
        auto z = lower_bound(t.begin(), t.end(), *w);
        // if (i == q - 1)
        // {
        //     cout << x << " " << *u << " " << *w << " " << *z << " " << *(z - 1) << endl;
        // }
        ll ans1 = min({abs(x - *u) + abs(*u - *v), abs(x - *u) + abs(*u - *(v - 1)),
                       abs(x - *w) + abs(*w - *z), abs(x - *w) + abs(*w - *(z - 1))});

        u = lower_bound(t.begin(), t.end(), x);
        v = lower_bound(s.begin(), s.end(), *u);
        w = u - 1;
        z = lower_bound(s.begin(), s.end(), *w);
        ll ans2 = min({abs(x - *u) + abs(*u - *v), abs(x - *u) + abs(*u - *(v - 1)), abs(x - *w) + abs(*w - *z), abs(x - *w) + abs(*w - *(z - 1))});

        cout << min(ans1, ans2) << endl;
    }

    return 0;
}
