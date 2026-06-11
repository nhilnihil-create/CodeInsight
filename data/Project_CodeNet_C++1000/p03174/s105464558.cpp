#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=100+10,mod=1e9+7,inf=INT_MAX;
int n;
//2^n
const int bt=1<<21;
bool a[25][25];
ll dp[25][bt];


/*Note that the expression "mask | (1 << j)" sets j'th bit in mask.
*/
ll solve(int ind,int mask){
if(ind==n)return 1;
ll&r =dp[ind][mask];
if(r!=-1)return r;
ll ans=0;
for(int i=0;i<n;i++){
    if(a[ind][i]&&!(mask&1<<i)){
        int m=mask^(1<<i);
       ans+= solve(ind+1,m);
       ans%=mod;
    }
}
return r=ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

cin>>n;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
       cin>>a[i][j];
    }
}
memset(dp,-1,sizeof dp);
cout<<solve(0,0);

    return 0;
}
