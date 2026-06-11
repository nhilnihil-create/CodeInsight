#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>

using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)

#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define op(i) cout << (i) << endl;
#define F first
#define S second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll mod = 1e9 + 7;
const ll infl = 1e17;

ll n, m;
bool dist[100005][2];
int main()
{
    cin >> n >> m;
    rep(i, n) rep(j, 2) dist[i][j] = false;
    map<ll, set<ll>> edge;
    ll a,b;
    rep(i,m){
        cin >> a >> b;
        a--;
        b--;
        edge[a].insert(b);
        edge[b].insert(a);
    }
    dist[0][0] = true;
    set<ll> check;
    check.insert(0);
    while (!(check.empty())){
        ll now = *check.begin();
        check.erase(now);
        for (auto nex:edge[now]){
            if (dist[now][0] && !(dist[nex][1])){
                dist[nex][1] = true;
                check.insert(nex);
            }
            if (dist[now][1] && !(dist[nex][0])){
                dist[nex][0] = true;
                check.insert(nex);
            }
        }
    }
    ll x = 0, y = 0, z = 0;
    rep(i,n){
        if (dist[i][0] && dist[i][1])
            x++;
        else if (dist[i][0])
            y++;
        else if (dist[i][1])
            z++;
    }
    ll ans = n * (n - 1) / 2 - y * (y - 1) / 2 - z * (z - 1) / 2;
    cout << ans - m << endl;
}
