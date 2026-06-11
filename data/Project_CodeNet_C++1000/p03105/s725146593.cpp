#include<bits/stdc++.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);

        int m=b/a;
        if(m>=c&&m!=0)
       {
          printf("%d\n",c);
          
       }
       if(m<c&&m!=0)
        {printf("%d\n",m);
        //printf("He may not be able to be satisfied.\n");
        }
        if(m==0)
            printf("0\n");

}
