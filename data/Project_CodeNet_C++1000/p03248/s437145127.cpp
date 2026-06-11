#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	if(s[1]=='0'||s[n]=='1'){
		puts("-1");
		return 0;
	}
	for(int i=1;i<n;i++)
		if(s[i]!=s[n-i]){
			puts("-1");
			return 0;
		}
	int m=1;
	for(int i=1;i<n;i++){
		printf("%d %d\n",i+1,m);
		if(s[i]=='1')m=i+1;
	}
	return 0;
}