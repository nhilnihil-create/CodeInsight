#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	double p[n];
	for(int i=0;i<n;i++)
	cin>>p[i];
    
    double pb[n+1][n+1];
    for(int j=1;j<=n;j++)
    pb[0][j]=0.00;

    pb[0][0]=1.00;

    for(int i=1;i<=n;i++)
    {
    for(int j=0;j<=n;j++)
    {
    if(j>0)
    pb[i][j]=pb[i-1][j]*(1.0-p[i-1])+pb[i-1][j-1]*p[i-1];
    else
    pb[i][j]=pb[i-1][j]*(1.0-p[i-1]);    
    }
    }
    double ans=0.00;
    int j=(n+1)/2;
    while(j<=n)
    {
    ans+=pb[n][j];
    j++;
    }
    cout<<fixed<<setprecision(12)<<ans;
    return 0;
}