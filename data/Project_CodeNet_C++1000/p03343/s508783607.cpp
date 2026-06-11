#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[2005];
int main()
{
	int n,k,q,ans=1e9;
	scanf("%d%d%d",&n,&k,&q);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=0;i<n;i++)
	{
		int l=-1;
		vector<int> v;
		for (int j=0;j<=n;j++)
		{
			if (arr[j]<arr[i])
			{
				vector<int> tmp;
				for (int m=l+1;m<j;m++)
				tmp.push_back(arr[m]);
				sort(tmp.begin(),tmp.end());
				for (int m=0;m<=(int)tmp.size()-k;m++)
				v.push_back(tmp[m]);
				l=j;
			}
		}
		if (v.size()>=q)
		{
			sort(v.begin(),v.end());
			ans=min(ans,v[q-1]-v[0]);
		}
	}
	printf("%d",ans);
}