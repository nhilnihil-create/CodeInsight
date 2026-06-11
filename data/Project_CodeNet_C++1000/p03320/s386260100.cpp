#include <iostream>
#include <cstdio>
using namespace std;
double cal(long long x){
    long long y=10,len=1,sum=0,ret=x;
    while(y<=x)y=(y<<1)+(y<<3),++len;
    while(len--){
        y/=10;
        sum+=x/y;
        x%=y;
    }
    return ret*1.0/sum;
}
bool judge(long long x){
    long long a=1;
    while(a<=x){
        if(cal(x+a)<cal(x))return false;
        a=(a<<1)+(a<<3);
    }
    return true;
}
long long k,now;
int main(){
    scanf("%d",&k);
    while(k--){
        long long a=1;
        while(true){
            if(judge(now+a)){
                now+=a;
                break;
            }
            a=(a<<1)+(a<<3);
        }
        cout<<now<<endl;
    }
    return 0;
}
