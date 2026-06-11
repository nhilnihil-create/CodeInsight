
#include <bits/stdc++.h>
using namespace std;
bitset<4000002> dp;
int main()
{
    int n;
    cin>>n;
   dp[0]=1;
    int a[n],s=0;
    for(int i=0;i<n;i++)
    {
      int x;
        cin>>x;
      s+=x;
        dp|=(dp<<x);
    }
    int j=0;
    for(j=(s+1)/2;j<=s;j++)
    {
        if(dp[j])
            break;
    }
    cout<<j<<"\n";
    return 0;
}
