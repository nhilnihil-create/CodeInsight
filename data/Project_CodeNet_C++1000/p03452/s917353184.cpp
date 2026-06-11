


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

typedef unsigned long long ull;


int main(){
    ll n,m;
    cin >> n >> m;
    set<ll> check;
    map<ll, map<ll, ll>> branch;
    ll l, r, d;
    rep(i,m){
        cin >> l >> r >> d;
        l--;
        r--;
        check.insert(l);
        check.insert(r);
        branch[l][r] = d;
        branch[r][l] = -d;
    }
    vll dist(n, infl);
    while (!(check.empty())){
        ll start = *check.begin();
        check.erase(start);
        if (dist[start]!=infl)
            continue;
        dist[start] = 0;
        set<ll> c;
        c.insert(start);
        while (!(c.empty())){
            ll now = *c.begin();
            c.erase(now);
            for (auto p:branch[now]){
                if (dist[p.F]==infl){
                    dist[p.F] = dist[now] + p.S;
                    c.insert(p.F);
                }
                else if (dist[p.F] != dist[now]+p.S){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    ll MIN = infl,MAX=-infl;
    rep(i,n){
        if (dist[i]!=infl){
        MIN = min(dist[i], MIN);
        MAX = max(dist[i], MAX);
    }}
    if (MAX-MIN<=1e9){
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}