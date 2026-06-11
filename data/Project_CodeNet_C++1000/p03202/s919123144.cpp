#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
int now[200005];
vector <int> v;
int main()
{
	scanf("%d",&n);
	bool ok=1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i-1]>=a[i])
		    ok=0;
	}	   
	if(ok) 
	{
		cout<<1;
		return 0;
	}
	int l=1,r=n+1; 
	while(l+1<r)
	{
		int m=(l+r)/2;
        ok=1;
		int len=0;
		map<int,int>f;
		for(int i=0;i<n;i++)
		{
			if(a[i]>len)
			    len=a[i];
			else
			{
				while(!f.empty()&&f.rbegin()->first>=a[i])
				    f.erase(f.rbegin()->first);
				f[a[i]-1]++;
				int cur=a[i]-1;
				while(f[cur]>=m)
				{
					f.erase(cur);
					cur--;
					f[cur]++;
					if(cur<0)
					    ok=0;					
				}
				if(!ok)
					break;
				len=a[i];
			}			
		}
		if(ok)
		    r=m;
		else
		    l=m;
	}
	cout<<r;
	return 0;
}