#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<map>
#define LL long long
#define LD long double
using namespace std;
const int NN=100000 +117;
const int MM=100000 +117;
int read(){
	int fl=1,x;char c;
	for(c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
	if(c=='-'){fl=-1;c=getchar();}
	for(x=0;c>='0'&&c<='9';c=getchar())
		x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}
void open(){
	freopen("a.in","r",stdin);
	//freopen(".out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}


int m,n;
LL a[NN]={};
int ord[NN]={};
int siz[NN]={};
map<LL,int> ind;
bool cmp(int x,int y){
	return a[x]>a[y];
}
vector<int> p[NN]={};
int dis[NN]={};
void dfs(int x){
	for(int i=0;i<p[x].size();++i){
		int cur=p[x][i];
		dis[cur]=dis[x]+1;
		dfs(cur);
	}
}
int main(){
	//open();
	n=read();
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		ord[i]=i;
		ind[a[i]]=i;
	}
	sort(ord+1,ord+1+n,cmp);
	bool fl=0;
	for(int i=1;i<n;++i){
		int x=ord[i];
		siz[x]+=1;
		LL xt=a[x]-n+2*siz[x];
		if(xt>=a[x])fl=1;
		int tp=ind[xt];
		if(!tp){
			fl=1;
		}
		else{
			p[tp].push_back(x);
			siz[tp]+=siz[x];
		}
	}
	dfs(ord[n]);
	LL chk=0;
	for(int i=1;i<=n;++i)chk+=dis[i];
	if(chk!=a[ord[n]])fl=1;
	if(fl){
		printf("-1\n");
	}
	else{
		for(int x=1;x<=n;++x){
			for(int i=0;i<p[x].size();++i){
				printf("%d %d\n",x,p[x][i]);
			}
		}
	}

	close();
	return 0;
}