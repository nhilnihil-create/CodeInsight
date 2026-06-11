#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll INF=1LL << 60;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ll n; cin >> n;
    ll dp[n];
    ll a[n];
    for (int i=0;i<n;i++){
        cin >> a[i];
        dp[i]=INF;
    }
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    for (int i=2;i<n;i++){
        chmin(dp[i],dp[i-1]+abs(a[i]-a[i-1]));
        chmin(dp[i],dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout << dp[n-1] << "\n";
}













