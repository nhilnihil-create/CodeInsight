#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)

int main() {
    int K; cin >> K;
    vector<ll> A(K);
    REP(i,K) cin >> A[i];
    ll ans1, ans2;
    ll low = 0;
    ll high = 1e18;
    ll mid;
    while(high-low>1) {
        mid = (high+low) / 2;
        ll tmp = mid;
        REP(i,K) tmp = tmp/A[i]*A[i];
        if(tmp<2) low = mid;
        else high = mid;
    }
    ans1 = low;
    low = 0;
    high = 1e18;
    while(high-low>1) {
        mid = (high+low) / 2;
        ll tmp = mid;
        REP(i,K) tmp = tmp/A[i]*A[i];
        if(tmp<=2) low = mid;
        else high = mid;
    }
    ans2 = low;
    if(ans2-ans1) cout << ans1+1 << ' ' << ans2 << endl;
    else cout << -1 << endl;
    return 0;
}