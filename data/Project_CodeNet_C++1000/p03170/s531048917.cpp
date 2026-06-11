#include<bits/stdc++.h>
using namespace std;
#define Elhabashy ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
const int N=1e5+5,mod=1e9+7;
typedef long long ll;
int n,k,arr[110],dp[N][3];
int solve(int i=k,bool p=0){
    int &ret=dp[i][p];
    if(~ret)return ret;

    ret=!p;
    for(int x=1;x<=n;x++){
        if(arr[x]<=i){
            if(solve(i-arr[x],!p)==p){
                ret=p;
            }
        }
    }
    return ret;
}
int main()
{
    Elhabashy
    input();
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>arr[i];
    memset(dp,-1,sizeof dp);
    if(solve())cout<<"Second\n";
    else cout<<"First\n";


}
