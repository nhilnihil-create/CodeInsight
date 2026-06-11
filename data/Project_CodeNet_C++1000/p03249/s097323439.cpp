#include<algorithm>
#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#define debug(...) fprintf(stderr,__VA_ARGS__) 
#define ref(a,b,c) for(int a=b;a<=c;++a)
#define def(a,b,c) for(int a=b;a>=c;--a)
#define fi first
#define se second
using namespace std;
inline char nc(){
//	return getchar();
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++; 
}
template<class T>void read(T &x){
	x=0;int f=1,ch=nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x*=f;
}
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=1e5+10;
LL D[maxn];
LL f[maxn];
int n;
int p[maxn];
int siz[maxn];
map<LL,int>idx; 
vector<pii>an; 
inline int cmp(const int&a,const int&b){
	return D[a]>D[b];
}
bool solve(){
	ref(i,1,n)p[i]=i,siz[i]=1,f[i]=0;
	sort(p+1,p+n+1,cmp);
	ref(i,1,n-1){
		int u=p[i];
		if(!idx.count(D[u]-n+2*siz[u]))return 0;
		int fa=idx[D[u]-n+2*siz[u]]; 
		if(u==fa)return 0;
		an.push_back(make_pair(fa,u));
		siz[fa]+=siz[u];
		f[fa]+=f[u]+siz[u];
	}
	if(f[p[n]]!=D[p[n]])return 0;
	ref(i,0,n-2)printf("%d %d\n",an[i].fi,an[i].se);
	return 1;
}
int main(){
	read(n);
	ref(i,1,n){
		read(D[i]);
		idx[D[i]]=i;
	}
	if(!solve())puts("-1");
	return 0;
}