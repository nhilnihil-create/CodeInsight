#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define ull unsigned long long
#define ll long long
#define Pr pair<ull,ll>
#define mp make_pair
using namespace std;
const int N=20,Hs=233;//-----------------debug--------------------//
map<ull,ll> cnt[20];
/*Pr cnt[100000];
bool have[100000];*/
char s[N*2];
int rec[N];
int n;
ll ans;
void update(){
	ull val=0;
	for (int i=1;i<=rec[0];++i) val=val*Hs+(s[rec[i]]-'a'+1);
	for (int i=n,p=rec[0];i>=1;--i){
		if (rec[p]==i&&p>0){--p; continue;}
		val=val*Hs+(s[i]-'a'+1);
	}
	++cnt[rec[0]][val];
}
void dfs1(int x){
	if (x==n+1){
		update();
		return;
	}
	rec[++rec[0]]=x; dfs1(x+1);
	--rec[0]; dfs1(x+1);
}
void calc(){
	ull val=0;
	for (int i=rec[0];i>=1;--i) val=val*Hs+(s[rec[i]]-'a'+1);
	for (int i=n+1,p=1;i<=2*n;++i){
		if (p<=rec[0]&&rec[p]==i){++p; continue;}
		val=val*Hs+(s[i]-'a'+1);
	}
	if (cnt[rec[0]].find(val)==cnt[rec[0]].end()) return;
	ans+=cnt[rec[0]][val];
}
void dfs2(int x){
	if (x==2*n+1){
		calc();
		return;
	}
	rec[++rec[0]]=x; dfs2(x+1);
	--rec[0]; dfs2(x+1);
}

int main(){
#ifndef ONLINE_JUDGE
	//freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	scanf("%s",s+1);
	ans=0;
	dfs1(1);
	dfs2(n+1);
	printf("%lld\n",ans);
}
