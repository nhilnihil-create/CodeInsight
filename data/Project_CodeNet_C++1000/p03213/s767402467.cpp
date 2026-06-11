#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pair<int,int>>PF(int n)
{
	vector<pair<int,int>>v;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			int cnt=0;
			while(n%i==0)
			{
				n/=i;
				cnt++;
			}
			v.push_back(make_pair(i,cnt));
		}
	}
	if(n!=1)v.push_back(make_pair(n,1));
	return v;
}

int main()
{	
	int n,t[105]={},sum[5]={},ans=0;;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		vector<pair<int,int>>w=PF(i);
		for(int j=0;j<w.size();j++)t[w[j].first]+=w[j].second;
	}
	for(int i=1;i<=100;i++)
	{
		if(t[i]>=24)sum[0]++;
		if(t[i]>=14)sum[1]++;
		if(t[i]>=4)sum[2]++;
		if(t[i]>=2)sum[3]++;
		if(t[i]>=74)sum[4]++;
	}
	if(sum[0])ans+=sum[0]*(sum[3]-sum[0])+sum[0]*(sum[0]-1);
	if(sum[1])ans+=sum[1]*(sum[2]-sum[1])+sum[1]*(sum[1]-1);
	ans+=sum[2]*(sum[2]-1)*(sum[2]-2)/2+sum[2]*(sum[2]-1)/2*(sum[3]-sum[2]);
	ans+=sum[4];
	cout<<ans<<endl;
	return 0;
}