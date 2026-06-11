#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<vector>
#include<functional>
using namespace std;
typedef long long LL;
inline long long read()
{
	long long kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
int main()
{
	LL N,H,W;
	scanf("%lld%lld%lld",&N,&H,&W);
	LL asd=0;
	for(int i=1;i<=N;++i)
	{
		LL a,b;
		a=read()/H;b=read()/W;
		asd+=(a*b>0);
	}
	printf("%lld",asd);
}