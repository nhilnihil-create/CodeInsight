#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,total=0;
    scanf("%d",&num);

    while(num){
        total = total + num%10;
        num = num/10;
    }
    if(total==1)
        printf("10");
    else
        printf("%d",total);
    return 0;
}