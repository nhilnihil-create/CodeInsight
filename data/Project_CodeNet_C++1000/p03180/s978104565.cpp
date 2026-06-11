#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int lli;
const lli N=16;
lli dp1[1<<N],dp2[1<<N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    lli n;
    cin>>n;
    lli i,j,k,a[n][n];
    
    for(i=0;i<n;i++) for(j=0;j<n;j++) cin>>a[i][j];
    
    //O(2^n * n^2)
    //dp1[mask] => total score if on bit in mask are in one group  
    for(i=0;i<1<<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                for(k=j+1;k<n;k++)
                {
                    if(i&(1<<k))
                    {
                        dp1[i]+=a[j][k];
                    }
                }
            }
        }
    }
    
    //O(3^n)
    //dp2[mask] => max possible score of mask
    for(i=0;i<1<<n;i++)
    {
        for(j=i;j;j=(j-1)&i)
        {
            dp2[i]=max(dp2[i], dp1[j]+dp2[i-j]);
        }
    }
    
    cout<<dp2[(1<<n)-1];
    return 0;
}