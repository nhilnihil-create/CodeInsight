#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,x;
    scanf("%d %d %d",&a,&b,&x);
    if((a+b) < x)
        printf("NO");
    else if(a>x)
        printf("NO");
    else
        printf("YES");
    return 0;
}