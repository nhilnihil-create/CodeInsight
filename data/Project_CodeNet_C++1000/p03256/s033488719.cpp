//@winlere
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std; typedef long long ll;
inline int qr(){
	int ret=0,f=0,c=getchar();
	while(!isdigit(c)) f|=c==45,c=getchar();
	while( isdigit(c)) ret=ret*10+c-48,c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n,m;
char w[maxn];
vector<int> e[maxn<<1];
int usd[maxn<<1];
void add(int fr,int to){e[fr].push_back(to);}

void dfs(int now,int last){
	usd[now]=1;
	for(auto t:e[now])
		if(t^last){
			if(!usd[t]) dfs(t,now);
			else if(usd[t]!=-1) puts("Yes"),exit(0);
		}
	usd[now]=-1;
}

int main(){
	n=qr(); m=qr();
	scanf("%s",w+1);
	for(int t=1,a,b;t<=m;++t){
		a=qr(),b=qr();
		if(w[a]!=w[b]) add(a,b+n),add(b,a+n);
		else add(a+n,b),add(b+n,a);
	}
	for(int t=1;t<=n+n;++t)
		if(!usd[t]) dfs(t,0);
	puts("No");
	return 0;
}
