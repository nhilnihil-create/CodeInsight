#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[100010];
int main(){
	scanf("%s",s);
	int n=strlen(s),ans=n;
	for(int i=1;i<n;i++)
		if(s[i]!=s[i-1])
			ans=min(ans,max(i,n-i));
	cout<<ans;
	return 0;
}