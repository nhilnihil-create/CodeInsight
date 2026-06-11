#include <cstdio>
#include <algorithm>
int main(){
    int a,b,c,d;
    int x,y;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(a<b){
        x=a;
    }
    else{
        x=b;
    }
    if(c<d){
        y=c;
    }
    else{
        y=d;
    }
    int sum=x+y;
    printf("%d",sum);
}

