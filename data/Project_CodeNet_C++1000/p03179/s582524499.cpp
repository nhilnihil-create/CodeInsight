#include <bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for( int i = l; i <= r; i++ )
#define st string

int mod = 1e9+7;

void addMod( int & a, int b ) {
    a += b;
    if( a >= mod ) a -= mod;
}

int main() {
    int n; cin>>n;
    int dp[n+1][n+1];
    FOR(i,0,n) FOR(j,0,n) dp[i][j] = 0;
    st s; 
    cin>>s;
    dp[1][1] = 1;
    FOR(len,2,n) {
        int pref[n];
        memset(pref,0,sizeof(pref));
        FOR(i,1,len-1) {
            addMod(pref[i],dp[len-1][i]);
            addMod(pref[i],pref[i-1]);
        }
        FOR(curr,1,len) {
            int L,R;
            if( s[len-2] == '<' ) {
                L = 1;
                R = curr-1;
            } else {
                L = curr;
                R = len-1;
            }
            if( R >= L ) addMod(dp[len][curr],(pref[R]-pref[L-1]+mod)%mod);
        }
    } 
    int ans = 0;
    FOR(i,1,n) addMod(ans,dp[n][i]);
    cout<<ans<<"\n";
    return 0;
}