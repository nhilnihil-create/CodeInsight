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

int N,A,B;
vi v, ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> A >> B;
    int lo = (N+A-1)/A, hi = N+1-A;
    if (B < lo || B > hi) {
        cout << -1;
        return 0;
    }
    FOR(i,1,N+1) v.pb(i);
    
    int cur = 0;
    while (sz(v)) {
        vi V;
        F0R(i,A) if (sz(v)) V.pb(v.back()), v.pop_back();
        if (cur+1+sz(v) < B) {
            // cout << "A\n";
            int ne = B-(cur+1+sz(v)); 
            int mx = sz(v)?v.back():0;
            F0R(i,ne) {
                mx = max(mx,V.back());
                V.pop_back();
            }
            reverse(all(V));
            for (int i: V) ans.pb(i);
            FORd(i,1,mx+1) ans.pb(i);
            break;
        } else {
            // cout << "B\n";
            reverse(all(V));
            for (int i: V) ans.pb(i);
        }
        cur ++;
    }
    for (int i: ans) cout << i << " ";
}

// read the question correctly (is y a vowel?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)