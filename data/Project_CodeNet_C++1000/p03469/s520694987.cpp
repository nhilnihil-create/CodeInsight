#include <stdio.h>

int main(){
	char s[10]="2017/01/" ;
	for(int i=8;i<9;i++){
		scanf("2017/01/%s",&s[i]);
	}
	s[3]='8';
	printf("%s",s);
return 0;
}