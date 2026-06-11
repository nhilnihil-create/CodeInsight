//Love and Freedom.
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define inf 20021225
#define ll long long
using namespace std;
int a[(1<<18)|1];
int mx[1<<18][2];
int ans[1<<18];
bool cmp(int x,int y){return a[x]<a[y];}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<(1<<n);i++)
	{
		scanf("%d",&a[i]);
		mx[i][0] = i;
		mx[i][1] = (1<<n);
	}
	for(int i=0;i<(1<<n);i++)
	{
		int tmp[4]={0};
		for(int j=0;j<n;j++)
			if((i>>j)&1)
			{
				int _i = i^(1<<j);
				tmp[0] = mx[i][0]; tmp[1] = mx[i][1];
				tmp[2] = mx[_i][0]; tmp[3] = mx[_i][1];
				sort(tmp,tmp+4,cmp);
				mx[i][0] = tmp[3]; mx[i][1] = tmp[2]==tmp[3]?tmp[1]:tmp[2];
				//printf("%d %d\n",mx[i][0],mx[i][1]);
			}
		ans[i] = a[mx[i][0]] + a[mx[i][1]];
	}
	for(int i=1;i<(1<<n);i++)	ans[i] = max(ans[i],ans[i-1]);
	for(int i=1;i<(1<<n);i++)	printf("%d\n",ans[i]);
	return 0;
}