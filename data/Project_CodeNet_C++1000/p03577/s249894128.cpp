#include <cstdio>

char str[1000001];
int main(){
scanf("%s",str);
int length=0;
for(length=0;str[length];length++);
length-=9;
for(int i=0;i<=length;i++)putchar(str[i]);
} 