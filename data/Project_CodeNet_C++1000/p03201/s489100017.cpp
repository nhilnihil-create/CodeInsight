#include<bits/stdc++.h>
using namespace std;
long long n,a[222222];
vector<long long> v;
map<int,int> mp;
long long maxn=0;
int powerup(int n)
{
	int s=1;
	while(true)
	{
		s*=2;
		if(s>n)
		  break;
	}
	return s;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		if(a[i]>maxn)
		  maxn=a[i];
    }
    long long s=1,ans=0;
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		if(mp[a[i]]<=0)continue;
		int x=a[i];
		int y=powerup(x)-x;
		if(mp[y]){
			mp[x]--;
			mp[y]--;
			if(mp[y]>=0)
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
