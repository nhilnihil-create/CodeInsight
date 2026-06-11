#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
 
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gpu_hash_map<int, int> mp;*/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 62;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const double PI = acos(-1);
const double eps = -1e6;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 5002;
ll dp[mxN][mxN];
int n;
ll a, b;
int arr[mxN];
int pos[mxN];
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>a>>b;
    owo(i, 0, n) {
        cin>>arr[i];
        pos[arr[i]] = i;
    }
    memset(dp, INFLL, sizeof(dp));
    owo(i, 0, mxN) {
        dp[0][i] = 0;
    }
    owo(i, 1, n+1) {
        int p = pos[arr[i]];
        ll mn = INFLL;
        owo(j, 0, n+1) {
            mn = min(mn, dp[i-1][j]);
            if(j>pos[i]) {
                dp[i][j] = min(dp[i][j], mn+a);
            }else {
                dp[i][j] = min(dp[i][j], mn+b);
            }
            if(j==pos[i]) dp[i][n+1] = min(dp[i][n+1], mn);
            if(j==pos[i-1])mn = min(mn, dp[i-1][n+1]);
        }
        /*mn = INFLL;
        uwu(j, n+1, 0) {
            if(j==pos[i-1])mn = min(mn, dp[i-1][n+1]);
            if(j==pos[i]) dp[i][n+1] = min(dp[i][n+1], mn);
            mn = min(mn, dp[i-1][j]);
            if(j<=pos[i]) {
                dp[i][j] = min(dp[i][j], mn+b);
            }
        }*/
        /*owo(j, 0, n+2) {
            cout<<i<<" "<<dp[i][j]<<"\n";
        }*/
    }
    ll ans = INFLL;
    owo(i, 0, n+2) {
        ans = min(ans, dp[n][i]);
    }
    cout<<ans<<"\n";
    return 0;
}