#include<cstdio>

long long gcd(long long a,long long b){ return b?gcd(b,a%b):a; }

int main(){
    int n;
    scanf("%d",&n);
    int a = -1, b = -1, c = -1;
    int start = n/4;
    if(start==0) start++;
    for(long long i = 1; i <= 3500; i++){
        if(a!=-1) break;
        for(long long j = i; j <= 3500; j++){
            if(a!=-1) break;
            long long up = 4, down = n;
            up = up*i-down; down = down*i;
            if(up<=0) continue;
            up = up*j-down; down = down*j;
            if(up<=0) continue;
            //printf("i = %lld, j = %lld, up = %lld, down = %lld\n",i,j,up,down);
            long long g = gcd(up,down);
            up /= g, down /= g;
            if(up==1){
                a = i, b = j, c = down;
            }
        }
    }
    printf("%d %d %d\n",a,b,c);
    return 0;
}
