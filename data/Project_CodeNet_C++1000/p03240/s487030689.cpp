#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int n,F,x[101],y[101],h[101];
inline bool check(int X,int Y,int H)
{
	for(register int i=1;i<=n;i++)
		if((((H-abs(X-x[i])-abs(Y-y[i]))<0)?0:H-abs(X-x[i])-abs(Y-y[i]))!=h[i])
			return false;
	return true;
}
int main() 
{
	scanf("%d",&n);
	for(register int i=1; i<=n; i++) {
		scanf("%d%d%d",&x[i],&y[i],&h[i]);
		if(h[i]!=0)F=i;
	}
	for(int i=0;i<=100;i++) 
	{
		for(int j=0;j<=100;j++) 
		{
			if(check(i,j,abs(i-x[F])+abs(j-y[F])+h[F]))
			{
				cout<<i<<" "<<j<<" "<<(int)abs(i-x[F])+abs(j-y[F])+h[F]<<endl;
				return 0;
			}
		}
	}
	return 0;
}