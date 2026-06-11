#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve()
{
    int n;
    cin>>n;
    int dp[3];
    cin>>dp[0]>>dp[1]>>dp[2];
    for(int i=1; i<n; i++){
        int temp[3];
        for(int i=0; i<3; i++){
            int t;cin>>t;
            temp[i]=t+max(dp[(i+1)%3],dp[(i+2)%3]);
        }
        for(int i=0; i<3; i++){
            dp[i]=temp[i];
        }
    }
    cout<<max(dp[0],max(dp[1],dp[2]));
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
