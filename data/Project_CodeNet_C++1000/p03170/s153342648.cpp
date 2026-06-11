#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int dp[k+1];
    dp[0]=0;
    for(int i=1; i<=k; i++){
        dp[i]=0;
        for(int j=0; j<n; j++){
            if(i-a[j]>=0){
                dp[i]=max(dp[i],1-dp[i-a[j]]);
            }
        }
    }
    (dp[k]==1)?cout<<"First":cout<<"Second";
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
