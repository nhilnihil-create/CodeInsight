#include<cstdio>

int main(){
    long long k,a,b;
    scanf("%lld%lld%lld",&k,&a,&b);
    if(b-a<=2 || k<=(a-1)) printf("%lld\n",k+1);
    else{
        long long left = k-(a-1);
        long long ans = left/2*(b-a)+left%2+a;
        printf("%lld\n",ans);
    }
    return 0;
}
