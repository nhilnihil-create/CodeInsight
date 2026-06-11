#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[16][16];
ll dp[1<<16];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int s=0;s<1<<n;s++){
        for(int i=0;i<n;i++)if(s>>i&1){
            for(int j=i+1;j<n;j++)if(s>>j&1){
                dp[s]+=a[i][j];
            }
        }
    }
    for(int s=0;s<1<<n;s++){
        int rs=s^((1<<n)-1);
        for(int t=rs;t;t=(t-1)&rs){
            dp[s|t]=max(dp[s|t],dp[s]+dp[t]);
        }
    }
    cout<<dp[(1<<n)-1]<<endl;

    return 0;
}