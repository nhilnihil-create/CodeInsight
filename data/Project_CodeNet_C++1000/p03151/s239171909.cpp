#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
long long s1,s2;
priority_queue<long long>q;
int cnt;
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
		if(a[i]<b[i])
		{
			s2+=b[i]-a[i];
			cnt++;
		}
		else if(a[i]>b[i])
		{
			s1+=a[i]-b[i];
			q.push(a[i]-b[i]);
		}
	}
	if(s2>s1)
	{
		cout<<"-1";
		return 0;
	}
	if(s2==0)
	{
		cout<<"0";
		return 0;
	}
	while(!q.empty())
	{
		long long x=q.top();
		q.pop();
		s2-=x;
		cnt++;
		if(s2<=0)
		{
			cout<<cnt;
			return 0;
		}
	}

	return 0;
}