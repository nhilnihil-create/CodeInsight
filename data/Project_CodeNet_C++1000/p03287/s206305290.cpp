#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
	int n,m;cin>>n>>m;
	vector<int> a(n);
	int i;
	rep(i,n)cin>>a[i];
	vector<int> rem(n+1,0);
	rep(i,n)rem[i+1]=(rem[i]+a[i])%m;
	sort(all(rem));
	ll ans=0;
	int now=rem[0]; // rem[0]=0
	ll count=1;
	rep(i,n)
	{
		if(rem[i+1]==now)
		{
			count++;
		}
		else
		{
			now=rem[i+1];
			ans+=count*(count-1)/2;
			count=1;
		}
	}
	ans+=count*(count-1)/2;
	cout<<ans<<endl;
}
