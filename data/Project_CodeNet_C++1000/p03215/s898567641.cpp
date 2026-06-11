#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

const int bits=40;
int32_t main() {
    int n, k; cin>>n>>k; int a[n]; rep(i, n) cin>>a[i];
    vll elem; elem.reserve(n*(n+1)/2);
    ll pf[n+1]={0};
    rep1(i, n) {
        pf[i]=pf[i-1]+a[i-1];
        rep(j, i) elem.pb(pf[i]-pf[j]);
    }
    ll ans=0;
    for(int i=bits; i>=0; i--) {
        int cnt=0; bool vis[elem.size()]={0};
        rep(j, elem.size()) if(elem[j]&(1LL<<i)) cnt++, vis[j]=1;
        if(cnt<k) continue;
        ans|=(1LL<<i);
        vll cur; cur.reserve(cnt);
        rep(j, elem.size()) if(vis[j]) cur.pb(elem[j]);
        elem=cur;
    }
    cout<<ans<<endl;
}
