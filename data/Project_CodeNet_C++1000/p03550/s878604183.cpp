#include <bits/stdc++.h>
#include <complex>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,C,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

vec a(2002,0);
mat dp(2,vec(2001,-1));
ll dfs(bool xturn, ll num){
    if(dp[xturn][num] != -1) return dp[xturn][num];
    ll ans = abs(a[0] - a[num]);
    reps(i,1,num){
        ans = xturn ? max(ans, dfs(xturn^1, i)) : min(ans, dfs(xturn^1, i));
    }
    dp[xturn][num] = ans;
    return ans;
}
int main() {
    cin>>N>>H>>W;
    rep(i,N) cin>>a[N-1-i];
    a[N] = W;
    cout<<dfs(1,N)<<endl;
}