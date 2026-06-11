#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#define MAXN 200005
#define MAXM
#define LL long long
#define LD long double
using namespace std;

int n, tag, a[MAXN];

map<int, int>::iterator it;

bool check(int mid)
{
	map<int, int> num;
	for(int i=2; i<=n; i++)
	{
		if(a[i]>a[i-1]) continue;
		int temp=a[i];
		while(num[temp]>=mid)
		{
			temp--;
			if(temp==0) return false;
		}
		num[temp]++;
		num.erase(num.lower_bound(temp+1), num.end());
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
		if(i>1 && a[i]<=a[i-1]) tag=1;
	}
	if(!tag) {printf("1\n"); return 0;}
	int l=1, r=4e5, ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid, r=mid-1;
		else l=mid+1;
	}
	printf("%d\n", ans+1);
}
