#include <stdio.h>
 
int main()
{
    int a,b,i,sum=0;
    scanf("%d %d",&a,&b);
    char s[a+b+1];
    scanf("%s",s);
    for(i=0;i<a+b+1;i++){
        if(i!=a){
            if(s[i]>='0' && s[i]<='9')
            {sum++;}
        } else if(s[i]=='-')
        {sum++;}
    }
    (sum==a+b+1)? printf("Yes\n"): printf("No\n");
    return 0;
}