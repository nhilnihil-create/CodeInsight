#include <iostream>
using namespace std;
int dp[100005];
int main() {
	int n,k;
	cin>>n>>k;
	int a[n],i;
	for(i=0;i<n;i++)
	cin>>a[i];
	dp[0]=0;
	for(int i=1;i<=k;i++)
	{
		dp[i]=0;
		for(int j=0;j<n;j++)
		{
			if(i>=a[j]&&dp[i-a[j]]==0)
			{
				dp[i]=1;
				break;
			}
		}
		
	}
	if(dp[k]==1)
	cout<<"First"<<endl;
	else
	cout<<"Second"<<endl;
	return 0;
}