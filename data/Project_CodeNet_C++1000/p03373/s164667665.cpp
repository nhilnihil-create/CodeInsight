#include<cstdio>

long long min(long long a,long long b){ return a>b?b:a; }

long long max(long long a,long long b){ return a>b?a:b; }

int main(){
    long long a,b,c;
    long long x,y;
    scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y);
    long long ans = a*x+b*y;
    for(long long i = 1; i <= max(x,y); i++){
        long long cur = i*2*c+max(0,x-i)*a+max(0,y-i)*b;
        ans = min(ans,cur);
    }
    printf("%lld\n",ans);
    return 0;
}
