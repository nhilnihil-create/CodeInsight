#include<iostream>
#include<vector>
using namespace std;
int N,K;
string s;
main()
{
	cin>>N>>K>>s;
	vector<int>a;
	if(s[0]=='0')a.push_back(0);
	int p=1;
	for(int i=1;i<N;i++)
	{
		if(s[i]!=s[i-1])
		{
			a.push_back(p);
			p=1;
		}
		else p++;
	}
	a.push_back(p);
	if(s[N-1]=='0')a.push_back(0);
	vector<int>sum;
	sum.push_back(a[0]);
	int pre=a[0];
	for(int i=1;i<a.size();i+=2)
	{
		pre+=a[i]+a[i+1];
		sum.push_back(pre);
	}
	int ans=0;
	if(sum.size()<=K+1)
	{
		cout<<sum[sum.size()-1]<<endl;
	}
	else
	{
		int m=0;
		for(int i=K;i<sum.size();i++)
		{
			ans=max(ans,sum[i]-sum[i-K]+a[(i-K)*2]);
		}
		cout<<ans<<endl;
	}
}
