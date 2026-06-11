#include<bits/stdc++.h>
using namespace std;
#define Elhabashy ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}
const int N=23,mod=1e9+7;
typedef long long ll;
int n ,arr[N][N],dp[N][1<<N];
int solve(int i=0,int msk=0){
    if(i==n)return 1;
    int &ret=dp[i][msk];
    if(~ret)return ret;
    ret=0;
    for(int j=0;j<n;j++){
        if(arr[i][j]==1 && !((1<<j)&msk)){
            ret+=solve(i+1,msk|(1<<j));
            ret%=mod;
        }

    }
    return ret;
}
int main()
{
    Elhabashy
    input();
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>arr[i][j];
    }
    memset(dp,-1,sizeof dp);
    cout<<solve()%mod<<endl;
}
