#include<bits/stdc++.h>
#define For(i,a,b) for(i=(a);i<=(b);++i)
#define Forward(i,a,b) for(i=(a);i>=(b);--i)
#define Rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define Repe(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
template<typename T>inline void read(T &x)
{
	T s=0,f=1;char k=getchar();
	while(!isdigit(k)&&(k^'-'))k=getchar();
	if(!isdigit(k)){f=-1;k=getchar();}
	while(isdigit(k)){s=s*10+(k^48);k=getchar();}
	x=s*f;
}
/*void init()
{
}
void solve()
{
}*/
void done()
{
	printf("NO\n");
	exit(0);
}
int n,a[3];
char s[200010];
int main()
{
	//file();
	//init();
	//solve();
	scanf("%s",s);
	n=strlen(s)-1;
	Rep(i,0,n)++a[s[i]-'a'];
	int ma=max(a[0],max(a[1],a[2])),mi=min(a[0],min(a[1],a[2]));
	if(ma-mi>1)printf("NO\n");
	else printf("YES\n");
	return 0;
}

