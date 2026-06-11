#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long n,c[N],l,r,d[N],A;
pair<long long,long long>p[N];
vector<int>a[N];
void D(int k,int f)
{
	A+=d[k]; 
	for(int i=0;i<a[k].size();i++)
		if(a[k][i]!=f)
			d[a[k][i]]=d[k]+1,D(a[k][i],k);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first,p[i].second=i,c[i]=1;
	sort(p+1,p+n+1); 
	for(int i=n;i>1;i--)
	{
		l=1,r=i-1;
		while(l<r)
			if(p[(l+r)/2].first<p[i].first+2*c[i]-n)
				l=(l+r)/2+1;
			else
				r=(l+r)/2;
		if(p[l].first!=p[i].first+2*c[i]-n)
		{
			cout<<-1;
			return 0;
		}
		c[l]+=c[i],a[p[l].second].push_back(p[i].second),a[p[i].second].push_back(p[l].second);
	}
	D(p[1].second,0);
	if(A!=p[1].first)
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<a[i].size();j++)
			if(i<a[i][j])
				cout<<i<<" "<<a[i][j]<<'\n';
	return 0;
}