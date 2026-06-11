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
        max = (pow(2,k)*a) + b + c;
    else if (max==b)
        max = (pow(2,k)*b) + a + c;
    else if (max==c)
        max = (pow(2,k)*c) + a + b;

    printf("%d",max);
    return 0;
}