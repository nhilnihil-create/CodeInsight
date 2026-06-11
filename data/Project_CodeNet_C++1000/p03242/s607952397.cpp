#include<cstdio>
using namespace std;
char s[5];
int main(){
	scanf("%s",s+1);
	for(int i=1;i<=3;i++){
		if(s[i]=='1') s[i]='9';
		else if(s[i]=='9') s[i]='1';
		printf("%c",s[i]);
	}puts("");
	return 0;
}