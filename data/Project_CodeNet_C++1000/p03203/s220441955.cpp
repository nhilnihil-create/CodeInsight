#include<cstdio>
#include<algorithm>
#define x first
#define y second
typedef std::pair<int,int> pii;
inline void read(int&r)
{
	register char c;r=0;
	do c=getchar();while(c<'0'||c>'9');
	do r=r*10+c-'0',c=getchar();while(c>='0'&&c<='9');
}

pii a[200001];
int main()
{
	int h,w,n,i,j=0,l=1;
	read(h),read(w),read(n);
	for(i=0;i<n;i++)read(a[i].x),read(a[i].y);
	a[n++]=pii(h+1,1);
	std::sort(a,a+n);
	for(i=1;i<h;i++)
	{
		while(a[j].x<=i)j++;
		if(a[j].x==i+1)
			if(a[j].y<=l)
				return printf("%d\n",i),0;
			else if(a[j].y==l+1)
				l--;
		l++;
	}
	printf("%d\n",h);
}