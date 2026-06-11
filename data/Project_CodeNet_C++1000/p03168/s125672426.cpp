#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=3e3+5,mod=1e9+7,inf=INT_MAX;
ld p[N],c[N];
vector<vector<int> > adj;
multiset<int> ms;
ld dp[N][N];
    int n;

ld solve(int ind,int left)
{
    if(ind==n)
        return 1;
    ld ans1=0,ans2=0;
    ld& r=dp[ind][left];
    if(r!=-1)return r;
    if(left>0)
        ans2=solve(ind+1,left-1)*(1-p[ind]);
    ans1=solve(ind+1,left)*(p[ind]);
    return r=ans1+ans2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            dp[i][j]=-1;
    }
    cout<<fixed<<setprecision(15)<<solve(0,n/2);

    return 0;
}
