#include <cstdio>
using namespace std;
const int N=100005;
int p,dis[N],q1[N],l1,r1,q2[N],l2,r2;
bool vi[N][2],flag;
int read()
{	char x=getchar();
	while(x<48||x>57) x=getchar();
	int ans=0;
	while(x>=48&&x<=57)
	{	ans=(ans<<1)+(ans<<3)+(x^48);
		x=getchar();
	}
	return ans;
}
void add(int num)
{	int x;
	x=(num+1)%p;
	if(!vi[x][1]&&!vi[x][0])
	{	vi[x][1]=true;dis[x]=dis[num]+1;
		q2[r2]=x;r2++;
	}
	x=(num*10)%p;
	if(!vi[x][0])
	{	vi[x][0]=true;dis[x]=dis[num];
		q1[r1]=x;r1++;
		if(x==0) { flag=true;return;}
	}
}
void solve()
{	l1=1;r1=2;l2=r2=1;
	q1[1]=1;dis[1]=1;vi[1][0]=true;
	while(r1>l1||r2>l2)
	{	while(r1>l1)
		{	add(q1[l1]);l1++;
			if(flag) return;
		}
		while(r2>l2)
		{	if(vi[q2[l2]][0]) {l2++;continue;}
			vi[q2[l2]][0]=true;add(q2[l2]);l2++;
			if(flag) return;
			break;
		}
	}
}
int main()
{	p=read();
	solve();
	printf("%d\n",dis[0]);
	return 0;
}