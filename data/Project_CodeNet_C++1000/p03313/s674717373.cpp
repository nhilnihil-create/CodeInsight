#include <iostream>
#include <stdio.h>
using namespace std;
#define LL long long
const LL maxn = (1<<18)+22;
 
int a[maxn];
 
struct node
{
	int a,b;
}Max[maxn];
 
void f(int x,node &b)
{
	if(b.a==x||b.b==x) return;
	if(a[b.a]<a[x]) swap(b.a,b.b),b.a=x;
	else if(a[b.b]<a[x]) b.b=x;
}
 
 
int main()
{
	int n;
	scanf("%d",&n);
	int N=1<<n;
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
		Max[i].a=i;
		Max[i].b=N;
	}
	for(int i=1;i<N;i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				int k=i^(1<<j);
				f(Max[k].a,Max[i]);
				f(Max[k].b,Max[i]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<N;i++){
		ans=max(ans,a[Max[i].a]+a[Max[i].b]);
		printf("%d\n",ans);
	}
 
 
	return 0;
}