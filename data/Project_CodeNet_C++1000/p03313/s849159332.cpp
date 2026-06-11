#include<bits/stdc++.h>
using namespace std;
int n,a[444444],ans[444444];
pair<int,int> mx[444444];
void upd(int i,int x)
{
	if (x>mx[i].first)
	{
		mx[i].second=mx[i].first;
		mx[i].first=x;
	}
	else if (x>mx[i].second) mx[i].second=x;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<(1<<n);i++) scanf("%d",&a[i]);
	for (int i=0;i<(1<<n);i++)
	{
		for (int j=i;j;j=(j-1)&i)
		{
			upd(i,a[j]);
		}
		upd(i,a[0]); 
	}
	for (int i=0;i<(1<<n);i++) ans[i]=mx[i].first+mx[i].second;
	for (int i=1;i<(1<<n);i++) ans[i]=max(ans[i-1],ans[i]);
	for (int i=1;i<(1<<n);i++) printf("%d\n",ans[i]);
	return 0;
}