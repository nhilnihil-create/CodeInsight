#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
signed main()
{
    SPEED;
    int n;
    cin>>n;
    int a[n],b[n],c[n],dp1[n]={0},dp2[n]={0},dp3[n]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    dp1[0]=a[0];
    dp2[0]=b[0];
    dp3[0]=c[0];
    for(int i=1;i<n;i++)
    {
        dp1[i]=max(dp2[i-1],dp3[i-1])+a[i];
        dp2[i]=max(dp1[i-1],dp3[i-1])+b[i];
        dp3[i]=max(dp2[i-1],dp1[i-1])+c[i];
    }
    cout<<max({dp1[n-1],dp2[n-1],dp3[n-1]});
}