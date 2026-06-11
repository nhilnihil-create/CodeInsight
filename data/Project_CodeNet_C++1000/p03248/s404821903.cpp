#include<cstdio>
#include<cstring>
char S[1001000];
int a[100100],n;
int main(){
	scanf("%s",S+1);
	n=strlen(S+1);
	for(int i=1;i<=n;i++)a[i]=S[i]-'0';
	if(a[n]==1||a[1]==0)return puts("-1"),0;
	for(int i=1;i<n;i++)
		if(a[i]!=a[n-i])return puts("-1"),0;
	int root=1;
	for(int i=1;i<n;i++){
		printf("%d %d\n",root,i+1);
		if(a[i]==1) root=i+1;
	}	
}