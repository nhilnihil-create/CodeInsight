#include<bits/stdc++.h>  
using namespace std;
char s[200005];
int f[1<<26];
int main(){
	scanf("%s",&s);
	int n=strlen(s),td;
	for (int i=1;i<(1<<26);i++) f[i]=1000000000;
	for (int i=0,zt=0;i<n;i++){
		zt^=(1<<(s[i]-'a'));
		td=f[zt]+1;
		for (int j=0;j<26;j++) td=min(td,f[zt^(1<<j)]+1);
		f[zt]=min(f[zt],td);
	}
	printf("%d",td);
}