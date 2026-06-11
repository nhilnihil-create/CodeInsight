#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,max;
    scanf("%d %d",&a,&b);
    max = a+b;
    if((a-b) > max)
        max = a-b;
    if((a*b) > max)
        max = a*b;
    printf("%d",max); 
    return 0;
}