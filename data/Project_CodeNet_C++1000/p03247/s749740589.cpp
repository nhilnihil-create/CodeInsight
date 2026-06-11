#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline void open(const char *s)
{
	#ifndef ONLINE_JUDGE
	char str[20];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
//	sprintf(str,"%s.out",s);
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
const int N=1010;
int n,a[N],b[N],B;

inline void gao(int x,int y,int k)
{
	if(k==-1)return;
	if(abs(x)>=(1<<k)){
		if(x>0){
			cout<<'R';
			x-=(1<<k);
			return gao(x,y,k-1);
		}
		else{
			cout<<'L';
			x+=(1<<k);
			return gao(x,y,k-1);
		}
	}
	if(abs(y)>=(1<<k)){
		if(y>0){
			cout<<'U';
			y-=(1<<k);
			return gao(x,y,k-1);
		}
		else{
			cout<<'D';
			y+=(1<<k);
			return gao(x,y,k-1);
		}
	}
	if(abs(x)>abs(y)){
		if(x>0){
			cout<<'R';
			x-=1<<k;
			return gao(x,y,k-1);
		}
		else{
			cout<<'L';
			x+=1<<k;
			return gao(x,y,k-1);
		}
	}
	else{
		if(y>0){
			cout<<'U';
			y-=1<<k;
			return gao(x,y,k-1);
		}
		else{
			cout<<'D';
			y+=1<<k;
			return gao(x,y,k-1);
		}
	}
}

int main()
{
	n=rd();fo(i,1,n)a[i]=rd(),b[i]=rd();
	fo(i,1,n-1)if((abs(a[i])^abs(b[i])^abs(a[i+1])^abs(b[i+1]))&1)
		return puts("-1"),0;
	int f=~(abs(a[1])+abs(b[1]))&1;
	B=30;
	cout<<B+f+1<<'\n';
	of(i,B,0)cout<<(1<<i)<<' ';
	if(f){cout<<1;fo(i,1,n)++a[i];}
	cout<<'\n';
	fo(i,1,n){
		gao(a[i],b[i],B);
		if(f)cout<<'L';
		cout<<'\n';
	}
	return 0;
}