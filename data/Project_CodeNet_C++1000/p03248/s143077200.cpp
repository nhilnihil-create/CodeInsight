#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
char str[MAXN];
int n,tot,h[MAXN],nx[MAXN<<1],to[MAXN<<1],cnt;
void add_edge(int x,int y){
	to[++tot]=y;nx[tot]=h[x];h[x]=tot;
}
void link(int x,int y){
	add_edge(x,y);
	add_edge(y,x);
}
bool check(){
	if(str[1]=='0')return false;
	if(str[n]=='1')return false;
	for(int i=2;i<n;i++){
		if(str[i]=='1'&&str[n-i]!='1')
			return false;
		if(str[i]=='0'&&str[n-i]!='0')
			return false;
	}
	return true;
}
void dfs(int cur,int sz){
	int rsz=sz-1;
	for(int i=rsz;i>=1;i--){
		if(str[i]=='1'){
			while(rsz>=i){
				rsz-=i;
				link(cur,++cnt);
				dfs(cnt,i);
			}
			break;
		}
	}
	while(rsz){
		rsz-=1;
		link(cur,++cnt);
		dfs(cnt,1);
	}
}
void print(int x,int y){
	for(int i=h[x];i;i=nx[i]){
		if(to[i]==y)continue;
		printf("%d %d\n",x,to[i]);
		print(to[i],x);
	}
}
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	if(!check()){
		puts("-1");
		return 0;
	}
	cnt=1;
	dfs(cnt,n);
	print(1,0);
	return 0;
}
