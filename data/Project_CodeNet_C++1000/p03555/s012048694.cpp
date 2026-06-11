#include<stdio.h>
int main()
{
	char c,c1,c2,c3,c4,c5;
	scanf("%c %c %c %c %c %c",&c,&c1,&c2,&c3,&c4,&c5);
	if(c==c5&&c1==c4&&c2==c3){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}