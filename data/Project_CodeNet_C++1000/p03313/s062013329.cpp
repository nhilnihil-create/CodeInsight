#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define fi first
#define MN (1<<18)
#define mp(x,y) make_pair(x,y)
using namespace std;
inline int in(){
    int x=0;bool f=0;char c;
    for (;(c=getchar())<'0'||c>'9';f=c=='-');
    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}
typedef pair<int,int> pr;
int a[MN+5];
pr mx[2][MN+5],b[4];
int n,res;
inline bool cmp(pr x,pr y){return x>y;}
int main()
{
	n=in();
	for (int i=0;i<(1<<n);++i){
		a[i]=in();
		if (a[i]>mx[0][i].fi) mx[1][i]=mx[0][i],mx[0][i]=mp(a[i],i);
		else if (a[i]>mx[1][i].fi) mx[1][i]=mp(a[i],i);
		for (int j=0;j<n;++j) if (!(i&(1<<j))){
			int tot=0;
			b[0]=mx[0][i];b[1]=mx[1][i];
			b[2]=mx[0][i|(1<<j)];b[3]=mx[1][i|(1<<j)];
			sort(b,b+4,cmp);
			for (int k=0;k<4;++k){
				if ((!k)||b[k]!=b[k-1]) mx[tot++][i|(1<<j)]=b[k]; 
				if (tot==2) break;
			}
		}
		res=max(res,mx[0][i].fi+mx[1][i].fi);
		if (i) printf("%d\n",res);
	}return 0;
}