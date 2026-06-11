#include<bits/stdc++.h>
using namespace std;
char s[100000 + 233];
int main(){
	scanf("%s",s+1);
	int n = strlen(s+1);
	bool bad = s[n]-'0';
	for(int i=1;i<n;i++){
		if(s[i]!=s[n-i])bad = 1;
	}
	if(s[1]=='0')bad = 1;
	s[1] = '0';
	if(bad){
		puts("-1");
		return 0;
	}
	int last = 1;
	for(int i=2;i<=n;i++){
		if(s[i-1]=='1'){
			printf("%d %d\n",last,i);
			last = i;
		}
		else{
			printf("%d %d\n",last,i);
		}
	}
}