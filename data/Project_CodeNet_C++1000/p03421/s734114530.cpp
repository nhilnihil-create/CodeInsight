#include<stdio.h>
#define rep(i,n) for(int i=0;i<(int)(n);++i)
int n,a,b,memo[300001]={1};

main() {
    scanf("%d%d%d",&n,&a,&b);
    if (n > 1LL*a*b || n < a+b-1) puts("-1");
    else {
        int now=b,cnt=n;
        while(1) {
            for(int i=0;i<b;++i){
                if (a == cnt) {
                    for(int k=0;k<=n;++k)if (!memo[k]) printf("%d ",k);
                    return 0;
                }
                cnt--;
                printf("%d ",now-i);
                memo[now-i] = 1;
            }
            a--;
            now = n<now+b?n:now+b;
        }
    }
}
