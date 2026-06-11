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
	int a,b,c;a=read();b=read();c=read();
	LL k=b+min(a+b+1,c);
	printf("%lld\n",k);
}