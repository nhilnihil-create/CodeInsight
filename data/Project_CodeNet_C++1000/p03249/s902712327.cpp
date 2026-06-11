#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}

int n, num[MX], par[MX];
ll d[MX], ans;
vi rpar[MX];
map<ll,int> m;

void gen(int x, int d = 0) {
    ans += d;
    for (int i: rpar[x]) gen(i,d+1);
}

int main() {
    io();
    cin >> n;
    
    priority_queue<pl> q;
    FOR(i,1,n+1) {
        cin >> d[i];
        num[i] = 1;
        m[d[i]] = i;
        q.push({d[i],i});
    }
    while (1) {
        auto a = q.top(); q.pop();
        par[a.s] = m[a.f-n+2*num[a.s]];
        if (2*num[a.s] >= n) par[a.s] = 0;
        if (par[a.s] == 0) {
            if (sz(q) != 0) {
                cout << -1;
                exit(0);
            } else {
                gen(a.s);
                if (d[a.s] != ans) {
                    cout << -1;
                    exit(0);
                }
                FOR(i,1,n+1) if (par[i]) cout << i << " " << par[i] << "\n";
                exit(0);
            }
        } else {
            rpar[par[a.s]].pb(a.s);
            num[par[a.s]] += num[a.s];
        }
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/