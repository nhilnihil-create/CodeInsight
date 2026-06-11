#include<bits/stdc++.h>
#define ll long long
using namespace std;
int now,n,la,pr,tot,a[500001],b[500001];
char s[500001];
void build(int x,int y){
	tot++;
	a[tot]=x;b[tot]=y;
}
int main(){
	int i,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	if(s[1]=='0'||s[n]=='1')return puts("-1"),0;
	for(i=1;i<=n/2;i++)if(s[i]!=s[n-i])return puts("-1"),0;
	la=1;pr=1;now=2;
	build(la,la+1);
	la=2;
	for(i=2;i<=n/2;i++)if(s[i]=='1'){
		now=la;
		for(j=pr+1;j<i;j++)now++,build(la,now);
		build(la,now+1);
		la=now+1;
		pr=i;
	}
	for(i=la+1;i<=n;i++)build(la,i);
	for(i=1;i<n;i++)printf("%d %d\n",a[i],b[i]);
}