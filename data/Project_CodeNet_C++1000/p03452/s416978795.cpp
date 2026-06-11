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

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repf(i, a, b) for (int i = (int)a; i < (int)b; i++)
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

const ll mod = 1e9 + 7;
const ll infl = 1e17;

typedef unsigned long long ull;

int main()
{
    ll n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << "Yes" << endl;
        return 0;
    }
    map<ll, set<pll>> branch;
    ll l, r, d;
    set<ll> point;
    rep(i, m)
    {
        cin >> l >> r >> d;
        branch[l - 1].insert(mp(r - 1, d));
        branch[r - 1].insert(mp(l - 1, -d));
        point.insert(l - 1);
        point.insert(r - 1);
    }
    vector<ll> X(n, -infl);
    queue<ll> check;
    vector<bool> visited(n, false);
    for (auto x:point){
        if (X[x]!=-infl)
            continue;
        X[x] = 0;
        queue<ll> check;
        check.push(x);
        while (!(check.empty()))
        {
            ll now = check.front();
            check.pop();
            visited[now] = true;
            for (auto p : branch[now])
            {
                ll nex = p.F;
                ll d = p.S;
                if (X[nex] == -infl)
                {
                    X[nex] = X[now] + d;
                    check.push(nex);
                }
                else if (X[nex] != X[now] + d)
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
    }}
    ll MIN = infl, MAX = -infl;
    rep(i, n)
    {
        //cout << X[i] << " ";
        if (X[i] > -infl)
        {
            MIN = min(MIN, X[i]);
            MAX = max(MAX, X[i]);
        }
    }
    if (MAX - MIN <= 1e9)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
