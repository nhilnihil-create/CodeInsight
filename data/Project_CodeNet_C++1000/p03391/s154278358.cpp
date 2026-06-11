#include<cstdio>
long long a[200005], b[200005];

long long max(long long a,long long b){ return a>b?a:b; }

int main(){
    int n;
    scanf("%d",&n);
    long long sum = 0;
    for(int i = 1; i <= n; i++){ 
        scanf("%lld%lld",&a[i],&b[i]);
        sum += a[i];
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i]>b[i]){
            long long cur = sum-a[i]+a[i]-b[i];
            ans = max(ans,cur);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
