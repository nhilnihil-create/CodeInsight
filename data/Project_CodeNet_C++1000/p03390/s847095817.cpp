#include<cstdio>
#include<algorithm>

long long min(long long a,long long b){ return a>b?b:a; }

long long max(long long a,long long b){ return a>b?a:b; }

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long c = a*b-1;
    long long L = 1, R = min(2000000000,c);
    long long res = -1;
    while(L<=R){
        long long M = (L+R)/2;
        long long mid = (M+1)/2;
        long long value = mid*(M+1-mid);
        //printf("M = %lld, value = %lld\n",M,value);
        if(value>c){
            R = M-1;
        }
        else{
            res = M;
            L = M+1;
        }
    }
    if(a!=b) res--;
    printf("%lld\n",max(0,res));
    }
    return 0;
}
