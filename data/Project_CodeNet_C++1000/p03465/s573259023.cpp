#include <iostream>
#include <bitset>
using namespace std;
const int INF=0x3f3f3f3f,maxn=2010;
bitset<2000010> dp;
int a[maxn],n,sum,m;
int main()
{
	int i,j,k,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	sum+=a[i];
	}
    dp[0]=1;
    for(i=n-1;i>=0;i--)
		dp|=dp<<a[i];
    for(i=(sum+1)/2;i<=sum;i++)
        if(dp[i])
        {
            cout<<i;
            return 0;
        }
}