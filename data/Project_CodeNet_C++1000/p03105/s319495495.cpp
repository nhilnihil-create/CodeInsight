#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a,b,c,sum;
    scanf("%d%d%d",&a,&b,&c);
    sum=b/a;
    if(sum>c){
        printf("%d\n",c);
    }
    else{
        printf("%d\n",sum);
    }
    return 0;
}
