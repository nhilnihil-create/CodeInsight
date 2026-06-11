#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //int:2*10**9
typedef long double ld;
typedef pair<ll,ll> P;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define vec2(name,i,j) vector<vector<ll>> name(i,vector<ll>(j))
#define vec2f(name,i,j,k) vector<vector<ll>> name(i,vector<ll>(j,k))
#define vec3(name,i,j,k) vector<vector<vector<ll>>> name(i,vector<vector<ll>>(j,vector<ll>(k)))
#define vec3f(name,i,j,k,l) vector<vector<vector<ll>>> name(i,vector<vector<ll>>(j,vector<ll>(k,l)))
#define vec4(name,i,j,k,l) vector<vector<vector<vector<ll>>>> name(i,vector<vector<vector<ll>>>(j,vector<vector<ll>>(k,vector<ll>(l))))
#define vec4f(name,i,j,k,l,m) vector<vector<vector<vector<ll>>>> name(i,vector<vector<vector<ll>>>(j,vector<vector<ll>>(k,vector<ll>(l,m))))
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000 //14
//cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

int main(){
    ll n; cin >> n;
    vector<ll> a((1<<n));
    REP(i,(1<<n)) cin >> a[i];
    vec3f(dp,(1<<n),19,2,0);
    REP(i,(1<<n)){
        dp[i][0][0]=a[i];
        REP(j,18){
            if ((1<<j)&i){
                vector<ll> com;
                com.pb(dp[i][j][0]);
                com.pb(dp[i][j][1]);
                com.pb(dp[i&~(1<<j)][j][0]);
                com.pb(dp[i&~(1<<j)][j][1]);
                sort(com.rbegin(),com.rend());
                dp[i][j+1][0]=com[0];
                dp[i][j+1][1]=com[1];
            }
            else{
                dp[i][j+1][0]=dp[i][j][0];
                dp[i][j+1][1]=dp[i][j][1];
            }
        }
    }
    vector<ll> ans((1<<n));
    FOR(i,1,(1<<n)-1){
        ans[i]=max(ans[i-1],dp[i][18][0]+dp[i][18][1]);
        cout << ans[i] << endl;
    }
}