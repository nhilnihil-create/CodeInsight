#include <bits/stdc++.h>
using namespace std;
long long cnt,sum;
long long a[200005],b[200005];
vector<long long>v;
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
		if(a[i]>=b[i])
			v.push_back(a[i]-b[i]);
		else
		{
			sum+=(b[i]-a[i]);
			cnt++;
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		if(sum>0)
		{
			sum-=v[i];
			cnt++;
		}
	}
	if(sum>0)
		cnt=-1;
	cout<<cnt;

	return 0;
}