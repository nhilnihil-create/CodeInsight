#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,a[N],l,r,t;
vector<int>p,q;
bool C(int k)
{
	p.clear(),q.clear();
	for(int i=2;i<=n;i++)
		if(a[i]<=a[i-1])
		{
			if(k==1)
				return false;
			while(!p.empty()&&p[p.size()-1]>a[i])
				p.pop_back(),q.pop_back();
			if(!p.empty()&&p[p.size()-1]==a[i])
				q[q.size()-1]++;
			else
				p.push_back(a[i]),q.push_back(1);
			while(!p.empty()&&q[q.size()-1]==k)
			{
				t=p[p.size()-1],p.pop_back(),q.pop_back();
				if(!p.empty()&&p[p.size()-1]==t-1)
					q[q.size()-1]++;
				else
					p.push_back(t-1),q.push_back(1);
			}
			if(p[0]==0)
				return false;
		}
	return true;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	l=1,r=n;
	while(l<r)
		if(C((l+r)/2))
			r=(l+r)/2;
		else
			l=(l+r)/2+1;
	cout<<l;
	return 0;
}