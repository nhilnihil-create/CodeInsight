#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
ll dp[41][2];
int main(){
    int n;cin >> n;
    ll k;cin >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<41;i++){
        for(int j=0;j<2;j++){
            dp[i][j]=-LINF;
        }
    }
    dp[40][1]=0;
    int cnt;
    for(int i=39;i>=0;i--){
        int A=0,B=0;
        for(int j=0;j<n;j++){
            if(a[j]&(1ll<<i)) A++;
            else B++;
        }
        dp[i][0]=max(dp[i][0],dp[i+1][0]+(1ll<<i)*max(A,B));
        if(k&(1ll<<i)){
            dp[i][0]=max(dp[i][0],dp[i+1][1]+(1ll<<i)*A);
            dp[i][1]=max(dp[i][1],dp[i+1][1]+(1ll<<i)*B);
        }
        else{
            dp[i][1]=max(dp[i][1],dp[i+1][1]+(1ll<<i)*A);
        }
    }
    ll ans=max(dp[0][0],dp[0][1]);
    cout << ans << endl;
    return 0;
}