#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
using namespace std;
typedef long long ll;
inline void open(const char *s)
{
	#ifndef ONLINE_JUDGE
	char str[20];
	sprintf(str,"in%s.txt",s);
	freopen(str,"r",stdin);
//	sprintf(str,"out%s.txt",s);
//	freopen(str,"w",stdout);
	#endif
}
inline int rd()
{
	static int x,f;
	x=0;f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return f>0?x:-x;
}
int bin[21],L;

int main()
{
	bin[0]=1;fo(i,1,20)bin[i]=bin[i-1]<<1;
	L=rd();
	int t=upper_bound(bin,bin+21,L)-bin-1;
	int n,m,d;
	n=t+1;m=t<<1;
	int p=L-bin[t];
	fo(i,0,t)if(bin[i]&p)m++;
	cout<<n<<' '<<m<<endl;
	fo(i,1,n-1){
		cout<<i<<' '<<i+1<<' '<<bin[i-1]<<endl;
		cout<<i<<' '<<i+1<<" 0\n";
	}
	int K=L-bin[t];d=L;p=0;
	fo(i,0,t-1){
		if(bin[i]&K){
			cout<<i+1<<' '<<n<<' '<<(d-=bin[i])<<endl;
		}
	}
	return 0;
}
