#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
using namespace std;
int n,a[N+5];struct Data {int l,r,v;I Data(CI x=0,CI y=0,CI t=0):l(x),r(y),v(t){}}S[N+5];
I bool Check(CI x)
{
	RI i,T=0;for(i=1;i<=n;++i)
	{
		if(a[i]>a[i-1]) {S[++T]=Data(a[i-1]+1,a[i],0);continue;}
		W(a[i]<S[T].l) --T;S[T].r=a[i];
		W(T&&S[T].v==x-1) --T;if(!T) return 0;
		S[++T]=Data(S[T].r,S[T].r,S[T].v+1),--S[T-1].r<S[T-1].l&&(S[T-1]=S[T],--T),
		S[T].r^a[i]&&(S[++T]=Data(S[T].r+1,a[i],0),0);
	}return 1;
}
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	RI l=1,r=n,mid;W(l<r) Check(mid=l+r-1>>1)?r=mid:l=mid+1;return printf("%d\n",r),0;
}