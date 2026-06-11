#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(b<a){
        printf("0\n");
    }
    else{
        if(b/a>c){
            printf("%d\n",c);
        }
        else{
            printf("%d",b/a);
        }
    }
}
