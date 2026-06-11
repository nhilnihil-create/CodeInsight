#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005,p=1000000007;
int read(){
	int f=1,g=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
	return f*g;
}
int n,fl,siz[N],b[N],fa[N];
vector<int> e[N];
ll a[N],f[N],ans[N];
unordered_map<ll,int> h;
bool cmp(int x,int y){return a[x]<a[y];}
void work(int x){
	f[x]=siz[x]-1;
	for (auto y : e[x]){work(y);f[x]+=f[y];}
}
void calc(int x,ll s){
	ans[x]=f[x]+s+n-siz[x];
	for (auto y : e[x])
	calc(y,ans[x]-f[y]-siz[y]);
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) {scanf("%lld",a+i);h[a[i]]=i;b[i]=i;siz[i]=1;}
	sort(b+1,b+n+1,cmp);
	for (int i=n;i>1;i--){
		int x=b[i];
		fa[x]=h[a[x]+siz[x]-n+siz[x]];
		if (!fa[x]){puts("-1");return 0;}
		siz[fa[x]]+=siz[x];
		e[fa[x]].push_back(x);
	}
	work(b[1]);
	calc(b[1],0);
	for (int i=1;i<=n;i++)
	if (ans[i]!=a[i]){puts("-1");return 0;}
	for (int i=2;i<=n;i++) printf("%d %d\n",fa[b[i]],b[i]);
	return 0;
}