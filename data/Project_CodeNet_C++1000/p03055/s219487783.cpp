#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace io{
	const int l=1<<19;
	char *s,*t,buf[l],c;
	char gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,l,stdin);
			return s==t?EOF:*s++;
		}
		return *s++;
	}
	template<class IT>void gi(IT &x){
		x=0;c=gc();while(c<'0'||c>'9')c=gc();
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=gc();}
	}
}
using io::gc;
using io::gi;
template<class IT>void chkmin(IT &a,IT b){if(b<a)a=b;}
template<class IT>void chkmax(IT &a,IT b){if(a<b)a=b;}

const int N=200005;

int n,v,u,s;
vector<int>e[N];
int dfs(int v,int fa){
	int u,x=0,y;
	for(int i=0;i<(int)e[v].size();i++){
		u=e[v][i];
		if(u!=fa){
			y=dfs(u,v)+1;
			chkmax(s,x+y);
			chkmax(x,y);
		}
	}
	return x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&v,&u);
		e[v].push_back(u);
		e[u].push_back(v);
	}
	dfs(1,0);
	if(s%3==1)puts("Second");
	else puts("First");
	return 0;
}