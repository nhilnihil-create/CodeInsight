#include<cstdio>
#include<map>
using namespace std;
#define N 215000
map<int,int> tp;
int n,s[N];
bool check(int k)
{
	if(k==1){for(int i=2;i<=n;i++)if(s[i]<=s[i-1])return 0;return 1;}
	tp.clear();
	int ls=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>ls){ls=s[i];continue;}
		while(1)
		{
			if(!tp.size())break;
			map<int,int>::reverse_iterator it=tp.rbegin();
			if(it->first<=s[i])break;
			tp.erase(--(it.base()));
		}
		tp[s[i]]++;
		int t=s[i];
		while(tp[t]>=k){if(t==1)return 0;tp[t]-=k,tp[t-1]++,t--;}
		ls=s[i];
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	int lb=1,rb=n,as=n;
	while(lb<=rb)
	{
		int mid=(lb+rb)>>1;
		if(check(mid))as=mid,rb=mid-1;
		else lb=mid+1;
	}
	printf("%d\n",as);
}//