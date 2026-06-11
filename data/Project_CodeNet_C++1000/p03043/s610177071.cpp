#include <iostream>
using namespace std;
#include <math.h>
int main(void){
    // Your code here
    int a, b;scanf("%d%d",&a,&b);
    double ret = 0;
    for (int i=1; i<=a;i++){
        double tmp=1.0/a;
        int now=i;
        while(now < b){
            now*=2;
            tmp/=2;
        }
        ret+=tmp;
    }
    printf("%.12f\n",ret);
}