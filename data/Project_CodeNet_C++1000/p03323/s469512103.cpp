#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(b+1 == a)
        printf("Yay!");
    else if(a+1 == b)
        printf("Yay!");
    else if(a==b)
        printf("Yay!");
    else
        printf(":(");
    return 0;
}