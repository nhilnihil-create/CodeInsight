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
using namespace std;

/*
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long ll;

#define fi first
#define se second

using Graph = vector<vector<int>>;
using PAIR = pair<string, int>;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = 0;
    //左からl個、右からr個取り出す
    for (ll l = 0; l <= min(k, n); l++)
    {
        for (ll r = 0; r <= min(k - l, n - l); r++)
        {
            ll d = k - r - l;
            // cout << "l=" << l << ",r=" << r << ",d=" << d << endl;
            vector<ll> vec;
            ll tmp = 0;
            // cout << "AAAAAAAAA" << endl;
            for (ll i = 0; i < l; i++)
            {
                vec.push_back(v[i]);
                tmp += v[i];
            }
            // cout << "AAAAAAAAA" << endl;
            for (ll i = 0; i < r; i++)
            {
                vec.push_back(v[n - 1 - i]);
                tmp += v[n - 1 - i];
            }
            // cout << "AAAAAAAAA" << endl;
            sort(vec.begin(), vec.end());
            // if (l == 2 && r == 1)
            // {
            //     for (int i = 0; i < vec.size(); i++)
            //     {
            //         cout << vec[i] << " ";
            //     }
            //     cout << endl;
            // }
            // for (int i = 0; i < vec.size(); i++)
            // {
            //     cout << vec[i] << " ";
            // }
            // cout << endl;
            ll x = vec.size();
            for (ll i = 0; i < min(d, x); i++)
            {
                if (vec[i] < 0)
                {
                    tmp -= vec[i];
                }
            }
            ans = max(ans, tmp);
            // cout << ans << endl;
        }
    }
    cout << ans << endl;

    return 0;
}