#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	long long a[n],s[n+5];
	s[0]=0LL;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		s[i+1]=s[i]+a[i];
	}
	long long ans=s[n];
	int l=1,r=3;
	for (int i = 2; i < n-1; ++i)
	{
		while (l<i-1)
		{
			if (abs(s[l]-s[i]+s[l])<abs(s[l+1]-s[i]+s[l+1]))
			{
				break;
			}
			++l;
		}
		long long ll=s[l],lr=s[i]-s[l];
		while (r<n)
		{
			if (abs(s[r]-s[i]-s[n]+s[r])<abs(s[r+1]-s[i]-s[n]+s[r+1]))
			{
				break;
			}
			++r;
		}
		long long rl=s[r]-s[i],rr=s[n]-s[r];
		ans=min(ans,max({ll,lr,rl,rr})-min({ll,lr,rl,rr}));
	}
	cout<<ans<<endl;
	return 0;
}
