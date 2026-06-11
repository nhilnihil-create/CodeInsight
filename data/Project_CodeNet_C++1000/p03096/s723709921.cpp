/**
题意:从给定数组中,选择两个相同的数字,可将相同数字之间的数字变为和该相同数字一样,该操作可以进行不定次数;
思路:考虑存在交叉的情况,记录相邻相等数的位置,利用鸽巢定理直接进行dp即可;
*/
 
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
 
const ll mod = 1e9+7;
const int maxn = 5e5+7;
 
int pre[maxn],pos[maxn],a[maxn];;
ll dp[maxn];
 
int main (){
    int n;cin>>n;
    for(int i=0;i<n*2;i++) pre[i]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) pre[i]=pos[a[i]],pos[a[i]]=i;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(pre[i]!=0&&pre[i]!=i-1) dp[i]=(dp[i]+dp[pre[i]])%mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}
 
 