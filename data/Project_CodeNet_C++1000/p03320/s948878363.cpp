#include<cstdio>
 
long long getS(long long u){
    long long res = 0;
    while(u){
        res += u%10;
        u /= 10;
    }
    return res;
}
 
int getBit(long long u){
    int res = 0;
    while(u){
        res++;
        u /= 10;
    }
    return res;
}
 
long long getNumber(int cur,int cnt){
    long long res = cur;
    for(int i = 0; i < cnt; i++) res = res*10+9;
    return res;
}
 
long long min(long long a,long long b){ return a>b?b:a; }
 
int main(){
    long long k;
    scanf("%lld",&k);
    for(int i = 1; i <= min(9,k); i++) printf("%d\n",i);
    int cur = 0, before = 9, cnt = 1;
    int bug = 0;
    k -= min(9,k);
    while(k!=0){
        cur++;
        printf("%d",cur);
        for(int i = 1; i <= cnt; i++) printf("9");
        printf("\n");
        k--;
        if(cur==before){
            cur = cur/10+1;
            cnt++;
            if(before!=99) before += 10;
            else{
                if(!bug) bug = 1;
                else before += 10;
            }
            if(k==0) break;
            printf("%d",cur);
            for(int i = 1; i <= cnt; i++) printf("9");
            printf("\n");
            k--;
        }
    }
    return 0;
}
