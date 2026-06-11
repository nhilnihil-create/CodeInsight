#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

inline char gc()
{
	static const int L = 1000;
	static char sxd[L], *sss = sxd, *ttt = sxd;
	if(sss == ttt)
	{
		ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
		if(sss == ttt)
			return EOF;
	}
	return *sss++;
}

#define dd c = getchar()
inline int read(int& x)
{
	x = 0;
	char dd;
	bool f = false;
	for(; !isdigit(c); dd)
	{
		if(c == EOF)
			return -1;
		if(c == '-')
			f = true;
	}
	for(; isdigit(c); dd)
		x = (x << 1) + (x << 3) + (c ^ 48);
	if(f)
		x = -x;
	return 1;
}
#undef dd

int i,n,x,sum;
bitset<2000007>f;
int main()
{
	read(n);
	f[0]=1;
	for(i=1;i<=n;i++)
	{
		read(x);
		f|=f<<x;
		sum+=x;
	}
	for(i=(sum+1)/2;i<=sum;i++)
	{
		if(f[i])
		{
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}