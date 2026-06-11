#include<stdio.h>
main()
{
    long long a,b,c,i,x,y;
    while(scanf("%lld %lld %lld",&a,&b,&c)==3){
        x=0;
        while(x!=c){
            if(x%2==0){
                if(a%2!=0){
                    a--;
                    a=a/2;
                    b=b+a;
                    x++;
                }
                else{
                    a=a/2;
                    b=b+a;
                    x++;
                }
            }
            else{
                if(b%2!=0){
                    b--;
                    b=b/2;
                    a=a+b;
                    x++;
                }
                else{
                    b=b/2;
                    a=a+b;
                    x++;
                }
            }
        }
        printf("%lld %lld\n",a,b);
    }
}
