#include <bits/stdc++.h>
/**
AHMAD;HASSAN;SAEED
*/
using namespace std;
vector<long long>sum;

int n;
int cnt=0;
vector<vector<long long> >dp(405,vector<long long>(405,-1ll));
long long slv(int i=0,int j=n-1){
    cnt++;
    if(i==j)
        return 0ll;
    if(dp[i][j]!=-1ll)
        return dp[i][j];
    long long ad=LONG_LONG_MAX;
    for(int k=i+1;k<=j;k++){
        ad=min(ad,slv(i,k-1)+slv(k,j));
    }
    return dp[i][j]=ad+sum[j+1]-sum[i];
}


int main()
{
    cin>>n;
    vector<long long>v(n+1);
    for(int i=0;i<n;i++){
        long long tm;
        cin>>tm;
        v[i+1]=v[i]+tm;
    }
    sum=v;
    cout<<slv()<<'\n';
/**
10
10
1 1 1 1 1 1 1 1 1 1
*/
    return 0;
}
