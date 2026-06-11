#include <stdio.h>

int main(){
    char name [52];
    int b;
    int c;
    scanf("%d %d", &c , &b);
    getchar();
    scanf("%[^\n]", name);
    name[b-1] += 32;
    printf("%s", name );
	return 0;
}