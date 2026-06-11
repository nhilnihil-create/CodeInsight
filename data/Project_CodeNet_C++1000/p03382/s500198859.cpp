#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100005;
int n,a[N];
//3 4 6 7
int Dis(int x,int y)
{
	return abs(x-(y+1)/2);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ansl=a[1];
	for(int i=1;i<n;i++)
	  if(Dis(a[i],a[n])<Dis(ansl,a[n])) ansl=a[i];
	printf("%d %d\n",a[n],ansl);
	return 0;
}