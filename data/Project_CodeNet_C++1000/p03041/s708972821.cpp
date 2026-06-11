#include <stdio.h>

int main(){
	int len,index;
	scanf("%d", &len);
	scanf("%d", &index);
	getchar();
	char name[len];
	scanf("%s",&name);
	name[index-1]+=32;
	printf("%s\n",name);
	return 0;
}