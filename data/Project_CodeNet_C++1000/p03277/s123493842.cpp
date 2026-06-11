//G题，难点在于如何O(n)求出1个数大于0个数，可用前缀和或者树状数组等维护 
//复杂度O(n log(10^9)^2)，虽然log都是真log但常数很小，可以来个离散化把10^9优化成n 
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long n;//long long 警告 
int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
int a[100002],l=0x7fffffff,r;
void init()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
}
int c[100002];//int数组比bool数组调试的时候好看 
int sum;
int lowbit(int x)
{
	return x&(-x);
}
int tr[1000002];
int add(int x)
{
	for(int i=x;i<=1000000;i+=lowbit(i))
	tr[i]++;
}
int ask(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
	ans+=tr[i];
	return ans;
}
bool check(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x) c[i]=1;
		else c[i]=-1;
	}
	sum=-200000;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		add(-sum); 
		sum+=c[i];//sum每次变化的abs=1，所以插入排序效率一般会很高（O(1),但如果卡可以卡到O(n/4))，但是难写（需要使用链表维护啥的，还要维护多少个数小于指针）…… 
		ans+=i-ask(-sum-1);
	}
	if((ans<<2)>=n*(n+1)) return true;
	else return false;
//	也可用另一种做法   https://www.cnblogs.com/henry-1202/p/9537952.html 
}
void play()
{
	int mid;
	while(l<r)
	{
		memset(tr,0,sizeof(tr));
		mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<endl;
}
int main()
{
	init();
	play();
	return 0;
} 