#include<bits/stdc++.h>
#define int long long
using namespace std;

int num , k , a[100005];

int dp[100005];

const int oo=1e9+7;

int Min(int a , int b)
{
	if(a>b)return b;
	else return a;
}

main()
{
	cin >> num >> k;
	for( int i=1 ; i <= num ; ++i )
	{
		cin >> a[i];
		dp[i]=oo;
	}
	dp[1]=a[1];
	dp[2]=abs(a[1]-a[2]);
    for(int i=3 ; i<=num ; i++)
    {
     	for(int j=1 ; j<=k ; j++)
     	{
     		if(i<=j)continue;
            if(i-j==1)dp[i]=Min(dp[i] , abs(a[i]-a[i-j]));
     		else dp[i]=Min(dp[i] , abs(a[i]-a[i-j])+dp[i-j]);
     	}
    }
    cout << dp[num]<<endl;
}