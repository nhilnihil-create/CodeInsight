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
const int MX = 200001;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); 
        re(rest...); 
    }
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s;
        return is;
    }
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        F0R(i,sz(a)) is >> a[i];
        return is;
    }
    
    // OUTPUT 
    
    template<class T> void pr(T& x) { cout << x; }
    template<class Arg, class... Args> void pr(Arg& first, Args&... rest) { 
        pr(first); 
        cout << ' ';
        pr(rest...); 
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}';
        return os;
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        os << '{';
        F0R(i,sz(a)) {
            if (i) os << ", ";
            os << a[i];
        }
        os << '}';
        return os;
    }
}

using namespace io;

int N,M;
string s;
set<int> adj[MX];
int co[MX][2];
bool bad[MX];
queue<int> todo;

int main() {
    setIO(); re(N,M,s);
    F0R(i,M) {
        int a,b; re(a,b); a--, b--;
        adj[a].insert(b), adj[b].insert(a);
    }
    F0R(i,N) {
        for (int j: adj[i]) co[i][s[j]-'A'] ++;
        if (min(co[i][0],co[i][1]) == 0) {
            bad[i] = 1;
            todo.push(i);
        }
    }
    int lef = N;
    while (sz(todo)) {
        lef --;
        int x = todo.front(); todo.pop();
        for (int i: adj[x]) if (i != x) {
            co[i][s[x]-'A'] --;
            if (!bad[i] && co[i][s[x]-'A'] == 0) {
                bad[i] = 1;
                todo.push(i);
            }
            adj[i].erase(x);
        }
    }
    if (lef == 0) {
        cout << "No";
        exit(0);
    }
    cout << "Yes";
}
/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/