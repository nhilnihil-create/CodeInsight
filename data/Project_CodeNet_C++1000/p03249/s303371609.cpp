//
// Created by Ильдар Ялалов on 28.10.2019.
//
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 1e18;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double dbl;
#define pb push_back
#define eb emplace_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define all(a) a.begin(),a.end()
bool debug = 0;
const int MAXN = 1e6 + 100;
const int LOG = 21;
const int mod = 1e9 + 7;
const int MX = (1e7 + 100) * 1.5;
typedef long long li;
const li MOD = 1000000000949747713ll;

template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &rhs) {
    out << "( " << rhs.first << " , " << rhs.second << " )";
    return out;
}


pll D[MAXN];

int sz[MAXN];

vector<int> g[MAXN];


ll sum  = 0;
void dfs(int v,int p,ll cur){
    sum += cur;
    for(int to:g[v]){
        if(to == p)
            continue;
        dfs(to,v,cur+1);

    }
}
void solve() {
    int n;
    cin >> n;

    map<ll,int> mp;
    for (int i = 1; i <= n; ++i) {
        cin >> D[i].fi;
        D[i].se = i;
        if(mp.count(D[i].fi) == 0){
            mp[D[i].fi] = i;
        }


        sz[i] = 1;
    }
    sort(D+1,D+n+1);

    vector<pii> edges;
    for(int j = n;j > 1;--j){
        int v = D[j].se;
        ll x = D[j].fi - n + 2 * sz[v];
        dout << v << " "<<D[j].fi <<" "<<x <<" : " <<endl;
        if(mp.count(x) == 0){
            cout <<"-1";
            return;
        }

        int to = mp[x];
        if(to == v){
            cout << -1 <<"\n";
            return;
        }
        edges.pb({v,to});

        g[v].pb(to);
        g[to].pb(v);
        sz[to] += sz[v];
    }

    dfs(D[1].se,-1,0);

    if(sum != D[1].fi){
        cout << -1;
        return;
    }
    for(auto x : edges){
        cout << x.fi<<" "<<x.se<<"\n";
    }


}

signed main() {
#ifdef zxc
    debug = 1;
    freopen("../input.txt", "r", stdin);
    //  freopen("../output.txt", "w", stdout);
#else

#endif //zxc
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    int t = 1;
    while (t--)
        solve();
    if (debug)
        cerr << endl << "time : " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
}