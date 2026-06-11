#include<iostream>
#include<cstdio>
using namespace std;
char s[3][4];
int main()
{
    scanf("%s%s%s",s[0],s[1],s[2]);
    printf("%c%c%c\n",s[0][0],s[1][1],s[2][2]);
    return 0;
}