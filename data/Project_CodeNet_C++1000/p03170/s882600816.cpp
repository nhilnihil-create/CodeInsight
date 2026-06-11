#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];

    bool dp[k+1]={false};
     
    for(int l=0;l<=k;l++)
    {
    for(int i=0;i<n;i++)
    {
    if(a[i]<=l&&!dp[l-a[i]])
    {
    dp[l]=true;
    break;
    }
    }
    }

    if(dp[k]==true)
    cout<<"First";
    else
    cout<<"Second";  

    return 0;
}