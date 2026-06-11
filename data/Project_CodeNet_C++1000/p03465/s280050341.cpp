#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500009;
const ll MX=999999999999;
ll a[N];
bitset<4000009> dp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll mn=MX; ll ans;
    ll n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		sum+=a[i];
	}
	dp[0]=1;
	for(int i=1;i<=n;i++)
    {
		dp=dp|(dp<<a[i]);
    }
	for(int i=4000000;i>=sum/2;i--)
	{
		if(dp[i])
		{
			if(abs(sum-2*i)<mn)mn=abs(sum-2*i),ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
