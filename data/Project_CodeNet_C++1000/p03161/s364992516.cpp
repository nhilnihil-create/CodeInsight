#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve()
{
    int n,k;
    cin>>n>>k;
    int h[n];
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    int dp[n];
    dp[0]=0;
    for(int i=1; i<n; i++){
        int c=INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j>=0){
                c=min(c,dp[i-j]+abs(h[i]-h[i-j]));
            }
        }
        dp[i]=c;
    }
    cout<<dp[n-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while(t--){
        solve();
        cout<<endl;
    }
}
