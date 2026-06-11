#include <bits/stdc++.h>
#define pb push_back
using namespace std;

inline int read()
{
	int sum=0,ff=1; char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(isdigit(ch))
		sum=sum*10+(ch^48),ch=getchar();
	return sum*ff;
}

bitset<2000*2000> B;

int n;

int main()
{
	n=read();
	B[0]=1;
	int alb=0;
	for ( int i=1;i<=n;i++ )
	{
		int x=read();
		alb+=x;
		B|=B<<x;
	}
	for ( int i=(alb+1)/2;i<=alb;i++ ) 
		if(B[i]) 
			return printf("%d\n",i),0;
	return 0;
}