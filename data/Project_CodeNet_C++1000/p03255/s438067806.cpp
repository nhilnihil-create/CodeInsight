#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ttgl, null_type,less<ttgl>, rb_tree_tag,tree_order_statistics_node_update>*/
 
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 62;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const double PI = acos(-1);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 200001;
ll f[mxN];
ll psum[mxN];
ll arr[mxN];
ll n, x;
ll ans = INFLL;
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>x;
    owo(i, 1, n+1) {
        cin>>arr[i];
    }
    f[0] = 5;
    f[1] = 5;
    owo(i, 2, mxN) {
        f[i] = f[i-1] + 2;
    }
    owo(i, 1, n+1) {
        psum[i] = psum[i-1] + arr[i];
    }
    owo(i, 1, n+1) {
        ll type;
        int cnt = 0;
        int lst = n;
        ll curr = i*x;
        for(int cnt = 0; lst>0; cnt++) {
            int nxt = max(lst-i, 0);
            ll add = (psum[lst]-psum[nxt])*f[cnt];
            if(__builtin_add_overflow(curr, add, &type)) curr = INFLL;
            else curr = curr+add;
            lst = nxt;
        }
        ans = min(ans, curr);
    }
    ans = ans  +  n*x;
    cout<<ans<<"\n";
    return 0;
}