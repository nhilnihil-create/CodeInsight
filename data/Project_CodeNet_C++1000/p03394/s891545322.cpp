#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
void readint(int &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
inline void chkmin(int &x,int y){x>y?x=y:0;}
inline void chkmax(int &x,int y){x<y?x=y:0;}
const int MAXN=30005;

int n;

int main()
{
	#ifndef ONLINE_JUDGE
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n);
	if(n==3)return 0*printf("2 5 63\n");
	printf("2 3 4 9 ");n-=4;
	enum(i,2,5000)
	{
		if(n<=1)break;
		printf("%d %d ",i*6-4,i*6-2);
		n-=2;
	}
	enum(i,2,2500)
	{
		if(n<=1)break;
		printf("%d %d ",i*12-9,i*12-3);
		n-=2;
	}
	enum(i,1,5000)
	{
		if(!n)break;
		printf("%d ",i*6);
		--n;
	}
	return 0;
}