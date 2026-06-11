#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,k,max;
    scanf("%d %d %d %d",&a,&b,&c,&k);

    max = a;
    if(b>max)
        max = b;
    else if(c>max)
        max = c;
    
    if(max==a)
        max = ((1<<k)*a) + b + c; //
    else if (max==b)
        max = ((1<<k)*b) + a + c;
    else if (max==c)
        max = ((1<<k)*c) + a + b;

    printf("%d\n",max);
    return 0;
}