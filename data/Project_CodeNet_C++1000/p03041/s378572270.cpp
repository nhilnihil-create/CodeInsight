#include <stdio.h>
#include <string.h>
int main(){

char name[50];
char n;
int K, N;
scanf("%d %d\n", &N, &K);
scanf("%s", &name);
name[K-1] += 32;
printf("%s", name);

return 0;
}
