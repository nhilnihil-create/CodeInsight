/*
这是Task F,但是网址是 d 。。。 
*/
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
#define int long long
#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n"

inline int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*y;
}
void put(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>=10) put(x/10);
    putchar((x%10)+48);
}
int n,a[N],id[N],siz[N],fa[N];
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline int cmp(const int&A,const int&B){
	return a[A]<a[B];
}
vector<int> l[N];
int dfs(int x){
//	cout<<x<<"       ljsn\n";
	int num=siz[x]-1;
	for(int i=0;i<l[x].size();i++) num+=dfs(l[x][i]);
	return num;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();id[i]=fa[i]=i;siz[i]=1;
	}
	sort(id+1,id+n+1,cmp);sort(a+1,a+n+1);
	int root=0;
	for(int i=n,pos,fx;i>=1;i--){
		fx=find(i);
		pos=lower_bound(a+1,a+n+1,a[i]-n+2*siz[i])-a;
		while(pos<=n&&fx==find(pos)) ++pos;
		if(a[pos]!=a[i]-n+2*siz[i]){
//			cout<<root<<"\n";
			if(!root){
				root=i;
				continue;
			}
			puts("-1");
			return 0;
		}
		siz[pos]+=siz[i];
		l[pos].push_back(i);
		fa[fx]=find(pos);
//		cerr<<i<<"\n";
	}
//	cout<<root<<"\n";
	int res=dfs(root);
//	cout<<res<<" "<<a[root]<<"\n";
	if(res!=a[root]){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<l[i].size();j++) cout<<id[i]<<" "<<id[l[i][j]]<<"\n";
	}
//	fclose(stdin);
//	fclose(stdout);
    return 0;
}
