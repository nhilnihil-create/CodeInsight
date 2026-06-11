#include<bits/stdc++.h>
using namespace std;
#define Elhabashy ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
const int N=400+5,mod=1e9+7;
typedef long long ll;
int n,arr[N];
ll dp[N][N];
ll solve(int i=1,int j=n){
    if(i==j)return 0;
    ll &ret=dp[i][j];
    if(~ret)return ret;
    ret=1e18;
    ll sum=0;
    for(int a=i;a<=j;a++)sum+=arr[a];

    for(int x=i;x<j;x++)
        ret=min(ret,sum + solve(i,x) + solve(x+1,j));
    

    return ret;

}
int main()
{
    Elhabashy
    input();
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    memset(dp,-1,sizeof dp);
    cout<<solve()<<endl;
}
