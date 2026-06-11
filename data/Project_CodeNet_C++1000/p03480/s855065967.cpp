#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char mt,s[100001];
int mark=1,ans=1000000000,a,b,p[100001];
int main(){
	scanf("%s",s);
	a=strlen(s);
	for(int i=0;i<a-1;i++){
		if(s[i]!=s[i+1]){
			mark=0;
			ans=min(ans,max(i+1,a-i-1));
		} 
	}
	if(mark) {
		printf("%d",a);
	}
	else printf("%d",ans);
	return 0;
}