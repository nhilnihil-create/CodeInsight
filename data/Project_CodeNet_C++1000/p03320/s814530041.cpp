#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
inline LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
inline int s(LL x)
{
	int tmp=0;
	while(x){
		tmp+=x%10;
		x/=10;
	}
	return tmp;
}
inline bool cmp(const LL &a,const LL &b)
{
	LL t1=a*s(b);LL t2=b*s(a);
	if(t1!=t2)	return t1<t2;
	return a<b;
}
LL k,tmp,a[1500008],tmp2,num,maxi;
int main()
{
	k=read();
	for(int i=1;i<=9999;++i){
		a[++num]=i;
		tmp2=1;
		for(int j=1;j<=11;++j){
			tmp2*=10;
			tmp=i*tmp2+tmp2-1;
			a[++num]=tmp;
			
		}
	}
	sort(a+1,a+num+1,cmp);
	unique(a+1,a+num+1);
	tmp=1;
	while(k){
		while(a[tmp]<maxi)	++tmp;
		maxi=a[tmp];
		printf("%lld\n",a[tmp]);
		++tmp;
		--k;
	}
	return 0;
}