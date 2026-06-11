#include <bits/stdc++.h>

using namespace std;

#define li long long int
#define FOR(i,l,r) for( int i = l-(l>r); i != r-(l>r); i += 1-2*(l>r) )
#define all(X) (X).begin(),(X).end()
#define vi vector<int>
#define vl vector<li>
#define vvi vector<vector<int>>

int nax = 30000;

void upd( li & a, li b ) {
    a = max(a,b);
}

bool comp( vi & a, vi & b ) {
    return a[0]+a[1] < b[0]+b[1];
}

int main() {
    int n; cin>>n;
    vvi B(n,vi(3,0));
    FOR(i,0,n) {
        FOR(j,0,3) cin>>B[i][j];
    }
    sort(all(B),comp);
    vl dp(nax,0);
    vl temp(nax,0);
    FOR(i,0,n) {
        int w = B[i][0], s = B[i][1];
        li v = B[i][2];
        temp = dp;
        FOR(j,0,s+1) {
            upd(temp[j+w],dp[j]+v);
        }
        dp = temp;
    }
    li ans = 0;
    FOR(i,0,nax) ans = max(ans,dp[i]);
    cout<<ans<<"\n";
    return 0;
} 