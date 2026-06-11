#include <bits/stdc++.h>

using namespace std;

int val[10]={0,2,5,5,4,5,6,3,7,6};
int dp[100005];
int vis[20];
int main()
{
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        vis[a]=1;
        for(int j=val[a];j<=n;j++){
            dp[j]=max(dp[j],dp[j-val[a]]+1);
        }
    }
    int aux = n;
    while(aux!=0){
        for(int j=9;j!=0;j--){
            if(vis[j]&&aux>=val[j]&&dp[aux-val[j]]==dp[aux]-1){
                cout<<j;
                aux-=val[j];
                break;
            }
        }
    }
    cout<<endl;
    return 0;
}
