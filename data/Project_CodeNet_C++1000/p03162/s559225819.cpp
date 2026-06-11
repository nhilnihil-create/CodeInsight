#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i,x,n) for(int i=x; i<(int)(n);i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());

string yes="Yes",no="No";

int main() {
    int n;
    cin>>n;
    vin a(n),b(n),c(n);
    rep(i,n) cin>>a[i]>>b[i]>>c[i];
    vector<vector<int>> dp(n, vector<int>(3,1001001001));
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];
    rep(i,n-1){
        dp[i+1][0]=max(dp[i][1]+a[i+1],dp[i][2]+a[i+1]);
        dp[i+1][1]=max(dp[i][0]+b[i+1],dp[i][2]+b[i+1]);
        dp[i+1][2]=max(dp[i][1]+c[i+1],dp[i][0]+c[i+1]);
    }
    //cout<<dp[n-1][0]<<" "<<dp[n-1][1]<<" "<<dp[n-1][2]<<endl;
    sort(dp[n-1]);
    cout<<dp[n-1][2]<<endl;
}
