#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,a[1000000];
vector<pair<int,int>>v;

bool check(int d)
{
	v.clear();
	v.push_back(make_pair(0,0));
	for(int i=1;i<=n;i++)
		if(a[i]<=a[i-1])
		{
			while(v.back().first>a[i])
				v.pop_back();
			for(int j=a[i];;--j)
			{
				if(j<1)
					return false;
				int t=1;
				if(v.back().first==j)
					t=1+v.back().second,v.pop_back();
				if(t<d)
				{
					v.push_back(std::make_pair(j,t));
					break;
				}
			}
		}
	return true;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
