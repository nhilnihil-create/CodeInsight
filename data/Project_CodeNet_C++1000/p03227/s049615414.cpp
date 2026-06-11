#include<stdio.h>
#include<string.h>
main()
{
    char a[3];
    int i;
    while(scanf("%s",a)==1){
        if(strlen(a)==2){
            printf("%s\n",a);
        }
        else{
            for(i=2;i>=0;i--)
                printf("%c",a[i]);
            printf("\n");
        }
    }
}
