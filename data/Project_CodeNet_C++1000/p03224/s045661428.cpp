#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
inline int read(){
	int x=0,c;while(!isdigit(c=getchar()));
	while(x=x*10+c-'0',isdigit(c=getchar()));
	return x;
}
int n,m,s[1000][1000],len[maxn];
int main(){
	n=read();m=2*n;int k=1;
	for(;k*(k-1)<m;k++);
	if(k*(k-1)==m){
		printf("Yes\n");int tmp=0;
		for(int i=1;i<=k;i++)
			for(int j=i+1;j<=k;j++)tmp++,s[i][++len[i]]=tmp,s[j][++len[j]]=tmp;
		printf("%d\n",k);
		for(int i=1;i<=k;i++){
			printf("%d ",len[i]);
			for(int j=1;j<=len[i];j++){
				printf("%d",s[i][j]);
				if(j==len[i])printf("\n");else printf(" ");
			}
		}
	}else printf("No\n");
}