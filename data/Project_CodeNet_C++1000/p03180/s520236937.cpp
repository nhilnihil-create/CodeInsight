#include <bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for( int i = l ; i < r; i++ ) 
#define vi vector<int>
#define li long long int
#define vl vector<li>
#define vvl vector<vl>
#define pb push_back
#define lmi LLONG_MIN

int n;
vvl a;
vl dp;
vi po;
vl scores;

bool present( int mask, int pos ) {
    return (mask>>pos)&1;
}


void upd( li & a, li b ) {
    a = max(a,b);
}

void manage( int index, li score, vi & not_used, int mask, int Set ) {
    if( index == not_used.size() ) {
        upd(dp[mask],score+scores[Set]);
        return;
    }
    manage(index+1,score,not_used,mask,Set);
    manage(index+1,score,not_used,mask^po[not_used[index]],Set^po[not_used[index]]);
}

int main() {
    cin>>n;
    po.assign(n+4,0); FOR(i,0,n+4) po[i] = (1ll<<i);
    a.assign(n,vl(n,0));
    FOR(i,0,n) FOR(j,0,n) cin>>a[i][j];
    dp.assign(po[n],lmi);
    int ma = po[n];
    dp[0] = 0;
    scores.assign(ma,0);
    FOR(i,0,ma) {
        FOR(j,0,n) {
            if( !present(i,j) ) continue;
            FOR(k,j+1,n) {
                if( !present(i,k) ) continue;
                scores[i] += a[j][k];
            }
        }
    }
    FOR(i,0,ma) {
        vi not_used;
        FOR(j,0,n) {
            if( !present(i,j) ) not_used.pb(j);
        }
        manage(0,dp[i],not_used,i,0);
    }
    cout<<dp[ma-1]<<"\n";
    return 0;
}