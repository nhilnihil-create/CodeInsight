#include<bits/stdc++.h>
using namespace std;

int n,H,W,nw,r;
pair<int,int> a[200010];

int main()
{
	scanf("%d%d%d",&H,&W,&n);
	for (int i=1; i<=n; i++) scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1,a+1+n),nw=1,r=0;
	for (int i=1; i<=n; i++)
	{
		if (a[i].first>nw) r+=a[i].first-nw,nw=a[i].first;
		if (a[i].second>r+1) continue;
		if (a[i].second==r+1) r--; else return printf("%d\n",nw-1),0;
	}
	return printf("%d\n",H),0;
}