#pragma GCC optimize ("O3")
//#pragma GCC target ("avx2")
#pragma GCC target (sse, sse2, sse3, ssse3, sse4,popcnt,tune=native)

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define SZ(a) (int)(a.size())
#define Read() freopen("input.cpp", "r", stdin)
#define Write() freopen("output.cpp", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Unique(x)  x.erase(unique(all(x)), x.end())
#define pi acos(-1.0)
#define vec vector
#define mp make_pair
#define paii pair<int, int>
#define padd pair<dd, dd>
#define pall pair<ll, ll>
#define fr first
#define sc second
//#define endl "\n"
#define vec vector

using namespace std;

#define int long long

const int MAXN = 2e5 + 47, inf = 1e17;

int n;

void read() {
    cin >> n;
}

void solve() {
    vec<vec<int> > comp((n + 1) / 2);
    if(n % 2 == 0) loop(i, SZ(comp)) comp[i].pb(i + 1), comp[i].pb(n - i);
    else {
        loop(i, SZ(comp) - 1) comp[i].pb(i + 1), comp[i].pb(n - i - 1);
        comp.back().pb(n);
    }/*
    for(auto &a :comp) {
        for(int &c : a) cout << c << " ";
        cout << endl;
    }*/

    vec<paii> ans;
    loop(a, SZ(comp)) {
        for(int p1 : comp[a]) {
            FOR(b, a + 1, SZ(comp)) {
                for(int p2 : comp[b]) ans.pb({p1, p2});
            }
        }
    }
    cout << SZ(ans) << endl;
    for(paii &p : ans) cout << p.fr << " " << p.sc << endl;
}

signed main() {
    #ifdef COFFEE_MACHINE
        Read();
        Write();
    #endif
    CIN;

    int t = 1;
    //cin >> t;
    while(t--) {
        read();
        solve();
    }
}
