#include <bits/stdc++.h>
using namespace std;
const int N=200050;
char s[N],t[N];
int main()
{
	int n,m,q,x,y;
	scanf("%i %i %i",&n,&m,&q);
	scanf("%i %i",&x,&y);
	int D=n-x+1,U=x,R=m-y+1,L=y;
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1;i<=q;i++)
	{
		switch(s[i])
		{
			case 'L': L--;break;
			case 'R': R--;break;
			case 'U': U--;break;
			case 'D': D--;break;
		}
		if(min({L,R,D,U})<=0) return 0*printf("NO\n");
		//printf("%i %i %i %i\n",L,R,U,D);
		switch(t[i])
		{
			case 'L': R++;break;
			case 'R': L++;break;
			case 'U': D++;break;
			case 'D': U++;break;
		}
		L=min(L,m);
		R=min(R,m);
		U=min(U,n);
		D=min(D,n);
	}
	printf("YES\n");
	return 0;
}