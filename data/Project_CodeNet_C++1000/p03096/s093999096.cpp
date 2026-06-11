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

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define f0x(i, a, b) for (int i = (a); i < (b); i++)
#define fax(i, a) for (int i = 0; i < (a); i++)
#define faxd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define f0xd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll C[MX]; ll dp[MX]; map<ll, int> dpCnt; vl vals;
//dp[i] = sum of dp[C[i]] so far +

int main() {
    int N; cin >> N;
    fax(i,N){
      cin >> C[i];
    }
    fax(i,N-1){
   	if(C[i] == C[i+1]){
   		continue;
   	}
   	else{
   		vals.pb(C[i]);
   	}
   }
   vals.pb(C[N-1]);
   dp[0] = 1;
   dpCnt[C[0]] = 1;
   f0x(i,1,sz(vals)){
     dp[i] = dp[i-1] + dpCnt[vals[i]];
     dp[i] %= MOD;
     dpCnt[vals[i]] = dp[i];
   }
   cout << dp[sz(vals)-1]%MOD << "\n";
}
