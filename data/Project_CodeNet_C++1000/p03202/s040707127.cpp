#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int A[200010];
int sta[1000010],dep[1000010];
bool check(int mid)
{
	int head=0;
	sta[head]=0,dep[head]=0;
	for(int i=1;i<=n;i++)
	{
		if(A[i]>dep[head]){
			head++;
			dep[head]=A[i];
			sta[head]=0;
			sta[head-1]++;
		}
		else{
			while(dep[head]>=A[i])head--;
			int now=A[i]-1;
			while(head>=0&&dep[head]==now&&sta[head]>=mid)
			{
				now--;
				head--;
			}
			if(head<0)return false;
			if(dep[head]!=now){
				head++;
				sta[head]=1;
				dep[head]=now;
			}
			sta[++head]=0;
			dep[head]=A[i];
			sta[head-1]++;
		}
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&A[i]);
		if(A[i]<=A[i-1])flag=false;
	}
	if(flag){
		printf("1\n");
		return 0;
	}
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}