#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	char s[55];
	scanf("%s",s+1);
	int l=strlen(s+1);
	for(int i=1;i<=l-8;++i) putchar(s[i]);
	return 0;
}