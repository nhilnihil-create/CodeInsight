#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define ll long long
#define in(a) a=read()
#define out(a) printf("%d\n",a)
inline ll read(){
    char c=getchar();ll f=1,x=0;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
    return x*f;
}
#define mod 1000000007
void MOD(int &x){if(x>=mod)x-=mod;}
#define maxn 100010
#define inf (1<<30)

int l,head[maxn],to[maxn*2],nxt[maxn*2],v[maxn*2];
void add(int x,int y,int z){
	nxt[++l]=head[x];head[x]=l;to[l]=y;v[l]=z;
}
int bfs[maxn*10],d[maxn],u[maxn];
int main(){
	int n;
	in(n);
	for(int i=0;i<n;i++){
		add(i,(i+1)%n,1);
		add(i,i*10%n,0);
	}
	memset(d,0x3f,sizeof(d));
	int l=1,r=2;
	bfs[l]=0;d[0]=0;
	while(l<r){
		int x=bfs[l++];u[x]=0;
		for(int i=head[x];i;i=nxt[i]){
			int c=to[i];
			if(d[x]+v[i]<d[c]){
				d[c]=d[x]+v[i];
				if(!u[c]){
					u[c]=1;
					bfs[r++]=c;
				}
			}
		}
	}
	int ans=inf;
	for(int i=1;i<n;i++){
		if((i+1)%n==0)ans=min(ans,d[i]+1);
		if(i*10%n==0)ans=min(ans,d[i]);
	}
	out(ans);
}