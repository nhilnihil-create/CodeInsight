#include<bits/stdc++.h>
#define P pair<int,int>
#define fir first
#define sec second
using namespace std;
const int N=1000005;
int q[5],a[N],m,n,Max;
P f[N];
P up(P A,P B)
{
	q[1]=A.fir;q[2]=A.sec;q[3]=B.fir;q[4]=B.sec;
	sort(q+1,q+5);
	return P(q[4],q[3]);
}
int main()
{
	scanf("%d",&m);n=1<<m;
	for (int i=0;i<n;i++) scanf("%d",&f[i].fir);
	for (int i=1;i<n;i<<=1)
	  for (int j=0;j<n;j++)
	    if (!(j&i)) f[j|i]=up(f[j|i],f[j]);
	for (int i=1;i<n;i++)
	  printf("%d\n",Max=max(Max,f[i].fir+f[i].sec));
	return 0;
}