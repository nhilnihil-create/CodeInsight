#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[10];
int main()
{
    scanf("%s",a);
    if(strlen(a)==2) printf("%s",a);
    else
    {
        for(int i=2;i>=0;i--)
            printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}
