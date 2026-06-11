#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
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

ll K;

ll sum(ll x) {
    int z = 0;
    while (x) {
        z += (x%10);
        x /= 10;
    }
    return z;
}

ld eval(ll x) {
    return (ld)x/sum(x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vl tri;
    FOR(i,1,1000) {
        ll z = i;
        while (z <= 1e18) {
            tri.pb(z);
            z = 10*z+9;
        }
    }
    sort(all(tri)); tri.erase(unique(all(tri)),tri.end());
    vl ans;
    ld mn = INF;
    F0Rd(i,sz(tri)) {
        mn = min(mn,eval(tri[i]));
        if (eval(tri[i]) <= mn) ans.pb(tri[i]);
    }
    reverse(all(ans));
    cin >> K;
    F0R(i,K) cout << ans[i] << "\n";
    /*ll po10 = 0;
    F0R(i,18) {
        FOR(j,1,10) ans.pb(j*(po10+1)+po10);
        po10 = 10*po10+9;
    }*/
    //for (auto a: ans) cout << a << "\n";
    cin >> K;
    /*ld mn = INF;
    FORd(i,1,10000000) {
        mn = min(mn,eval(i));
        if (eval(i) <= mn) cout << i << "\n";
    }*/
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS