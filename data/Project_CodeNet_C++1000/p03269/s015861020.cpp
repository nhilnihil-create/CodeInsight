#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int in(){
    int x=0;bool f=0;char c;
    for (;(c=getchar())<'0'||c>'9';f=c=='-');
    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}
int l[62],r[62],v[62],L,d,tot,res;
int main()
{
	L=in();
	for (d=1;(1<<d)<=L;++d);
	for (int i=1;i<d;++i){
		l[++tot]=i;r[tot]=i+1;v[tot]=(1<<(i-1));
		l[++tot]=i;r[tot]=i+1;v[tot]=0;
	}
	res=(1<<(d-1));
	for (int i=d;i>=2;--i){
		if (L&(1<<(i-2))){
			l[++tot]=i-1;r[tot]=d;v[tot]=res;
			res+=(1<<(i-2));
		}
	}
	printf("%d %d\n",d,tot);
	for (int i=1;i<=tot;++i)
	printf("%d %d %d\n",l[i],r[i],v[i]);
	return 0;
}