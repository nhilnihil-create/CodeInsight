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
    ll n,k; cin >> n >> k;
    ll dp[n];
    ll a[n];
    for (int i=0;i<n;i++){
        cin >> a[i];
        dp[i]=INF;
    }
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    if (k>n){
        for(int i=2;i<n+1;i++){
            for (int j=1;j<i+1;j++){
            chmin(dp[i],dp[i-j]+abs(a[i]-a[i-j]));
            }   
        }
    }
    else{
        for(int i=2;i<k;i++){
            for (int j=1;j<i+1;j++){
                chmin(dp[i],dp[i-j]+abs(a[i]-a[i-j]));
            }
        }
        for (int i=k;i<n;i++){
            for (int j=1;j<k+1;j++){
                chmin(dp[i],dp[i-j]+abs(a[i]-a[i-j]));
            }
        }
    }
    cout << dp[n-1] << "\n";
}













