#include <stdio.h>
int main()
{
    char s1[100];
    scanf("%s",s1);
    int i=0,cn=0;
    while(s1[i]!='\0'){
        if(s1[i]=='2'){
            cn++;
        }
        i++;
    }
    printf("%d\n",cn);
    return 0;
}
