#include<bits/stdc++.h>
using namespace std;
char s[200050];

int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	if (s[1]=='0'||s[len]=='1') return puts("-1"),0;
	for (int i=1;i<=len/2;++i)
		if (s[i]!=s[len-i]) return puts("-1"),0;
	int x=1;
	for (int i=1;i<len;++i) {
		printf("%d %d\n",x,i+1);
		if (s[i]=='1') x=i+1;
	}
	
}