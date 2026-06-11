#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a,b,k;
    scanf("%d%d%d",&a,&b,&k);
    if(a<b){
        swap(a,b);
    }
    int h[1001],j=0;
    for(int i=1;i<=b;i++){
        if(a%i==0&&b%i==0){
            h[j++]=i;
        }
    }
    sort(h,h+j);
    printf("%d\n",h[j-k]);
    return 0;
}
