#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1e9 + 7;

vector<ll> dx = {1, -1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

vector<vector<ll>> g;

vector<ll> x;
vector<ll> y;
vector<ll> h;

ll check(ll xx, ll yy)
{
    ll cur = -1;
    for (int i = 0; i < x.size(); ++i)
    {
        ll hh = h[i] + abs(x[i] - xx) + abs(y[i] - yy);
        if (h[i] != 0)
        {
            cur = hh;
            break;
        }
    }
    for (int i = 0; i < x.size(); ++i)
    {
        ll hh = h[i] + abs(x[i] - xx) + abs(y[i] - yy);
        if (h[i] != 0)
        {
            if (hh != cur)
            {
                return -1;
            }
        }
        else
        {
            if (max(cur - abs(x[i] - xx) - abs(y[i] - yy), 0ll))
            {
                return -1;
            }
        }
    }
    return cur;
}

int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n;
    cin >> n;
    x = vector<ll>(n);
    y = vector<ll>(n);
    h = vector<ll>(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i] >> h[i];
    }
    
    for (int i = 0; i <= 100; ++i)
    {
        for (int j = 0; j <= 100; ++j)
        {
            ll ret = check(i, j);
            if (ret != -1)
            {
                cout << i << " " << j << " " << ret << endl;
                return 0;
            }
        }
    }

    return 0;
}