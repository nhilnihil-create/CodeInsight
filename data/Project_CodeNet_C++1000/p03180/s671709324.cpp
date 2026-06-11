#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ull unsigned long long
#define N 100005
#define mod 1000000007
//#define mod 1e18
#define boost ios_base::sync_with_stdio(false);cin.tie(0)
#define prec(n) fixed<<setprecision(n)

#define mii map<int,int>
#define mll map<ll,ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi  first

#define se second
#define pb push_back
#define mp make_pair
#define pp pop_back
#define vii vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(c) c.begin(),c.end()
#define tr(it,c) for(it = c.begin() ; it!=c.end() ; it++)
int inf = INT_MAX ;
ll modulo(ll num,ll MOD=mod){ return ((num%MOD)+MOD)%MOD;} // for negative integer
ll power(ll b,ll e,ll MOD=mod){ll ans=1; while(e){if(e%2) ans=(ans*b)%MOD; b=(b*b)%MOD; e/=2;} return ans;}
ll inv(ll num,ll MOD=mod){ return power(modulo(num),MOD-2,MOD); }
ll gcd(ll a,ll b){ return ((b==0) ? a:gcd(b,a%b));}
const ll INF = 1e18L + 5;

vector<ll> pre; // preprocessing
// pre[mask] - score of group 'mask'
vector<ll> dp;

void rec(int i, const vector<int>& not_taken, ll score_so_far, int mask, int group) {
    if(i == (int) not_taken.size()) {
        dp[mask] = max(dp[mask], score_so_far + pre[group]);
        return;
    }
    rec(i + 1, not_taken, score_so_far, mask, group);
    rec(i + 1, not_taken, score_so_far, mask ^ (1 << not_taken[i]),
        group ^ (1 << not_taken[i]));
}

// O(2^n * n^2 + 3^n)

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<ll>> in(n, vector<ll>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%lld", &in[i][j]);
        }
    }
    pre.resize(1 << n);
    // O(2^n * n^2)
    for(int mask = 0; mask < (1 << n); ++mask) {
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) {
                for(int j = i + 1; j < n; ++j) {
                    if(mask & (1 << j)) {
                        pre[mask] += in[i][j];
                    }
                }
            }
        }
    }
    // dp[mask] - best total score if we grouped rabbits from 'mask' already
    dp.resize(1 << n, -INF);
    dp[0] = 0;
    // O(2^n * n + 3^n)
    for(int mask = 0; mask < (1 << n); ++mask) {
        vector<int> not_taken;
        for(int i = 0; i < n; ++i) {
            if(!(mask & (1 << i))) {
                not_taken.push_back(i);
            }
        }
        rec(0, not_taken, dp[mask], mask, 0);
    }
    printf("%lld\n", dp[(1<<n)-1]);
}
