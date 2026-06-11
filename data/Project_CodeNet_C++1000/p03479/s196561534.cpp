#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vpi = vector<pii>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpl = vector<pll>;
using vs = vector<string>;

int main()
{
    ll x, y;
    cin >> x >> y;
    ll cnt = 0;
    while(x<=y)
    {
        cnt++;
        x *= 2;
    }
    cout << cnt << endl;
    return 0;
}
