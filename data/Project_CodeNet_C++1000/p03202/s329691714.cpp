#include <cstdio>
#include <map>

using namespace std;

#define R register

const int MAXN=2e5+10;

int n;
int a[MAXN];

map<int,int> mp;

inline bool chk(int k)
{
	mp.clear();
	k--;
	for(R int i=2;i<=n;i++)
	{
		if(a[i-1]<a[i]) continue;
		if(k==0) return 0;
		while(!mp.empty()&&mp.rbegin()->first>a[i]) mp.erase(mp.rbegin()->first);
		int j=a[i];
		while(j&&mp[j]==k) mp.erase(j--);
		if(j) mp[j]++;
		else return 0;
	}
	return 1;
}

int main()
{
	scanf("%d",&n);
	for(R int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=1,r=n,mid,res=n;
	while(l<=r)
	{
		int mid=l+r;mid>>=1;
		if(chk(mid)) r=mid-1,res=mid;
		else l=mid+1;
	}
	printf("%d\n",res);
	return 0;
}