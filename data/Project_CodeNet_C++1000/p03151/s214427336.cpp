#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
long long s1,s2;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
	{
		s1+=a[i];
		s2+=b[i];
	}
	if(s1<s2)
	{
		cout<<"-1";
		return 0;
	}
	long long x=0,cnt=0;
	vector<long long>v;
	for(int i=0;i<n;i++)
	{
		if(a[i]<b[i])
		{
			x+=b[i]-a[i];
			cnt++;
		}
		else
			v.push_back(a[i]-b[i]);
	}
	sort(v.begin(),v.end(),greater<long long>());
	for(int i=0;i<v.size();i++)
	{
		if(x>0)
		{
			x-=v[i];
			cnt++;
		}
	}
	cout<<cnt;

	return 0;
}