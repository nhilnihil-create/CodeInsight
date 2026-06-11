#include <bits/stdc++.h>
int n,a[305][305],ans;
char s[305];
int check1(int x){
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (a[i][j]!=a[(j-x+n)%n][(i+x)%n]) return 0;
	return 1;
}
int check2(int x){
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (a[i][j]!=a[(j+x)%n][(i-x+n)%n]) return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s",s);
		for (int j=0;j<n;j++) a[i][j]=s[j]-'a';		
	}
	for (int i=0;i<n;i++)
		ans=ans+check1(i)*(n-i);
	for (int i=1;i<n;i++)
		ans=ans+check2(i)*(n-i);
	printf("%d\n",ans);
	return 0; 
}