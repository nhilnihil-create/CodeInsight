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
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

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

int Q;

ll get(ll pro) {
    ll lo = 0, hi = MOD;
    while (lo < hi) {
        ll mid = (lo+hi+1)/2;
        if (mid*(mid+1) < pro) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

ll get(ll A, ll B) {
    // A*B > (x*(x+1))
    ll x = get(A*B);
    ll lo = A, hi = max(lo,(ll)ceil((ld)A*B/(x+1))-1);
    return x+hi-lo;
    // A*B/x >= A*B/(x+1)+1 
    // x from B-1 to 1 
    // ceil(A*B/x)-1
}

ll solve(ll A, ll B) {
    if (A > B) swap(A,B);
    return A-1+get(A,B);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> Q;
    F0R(i,Q) {
        int A,B; cin >> A >> B;
        cout << solve(A,B) << "\n";
    }
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)