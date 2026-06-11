#include<cstdio>
long long x[100005], v[100005];
long long tx[100005], tv[100005];

long long max(long long a,long long b){ return a>b?a:b; }

long long solve(int n,long long c,long long x[],long long v[]){
    long long curSum = 0;
    for(int i = 1; i <= n; i++) curSum += v[i];
    long long ans = curSum-x[n];
    long long leftSum = 0, maxn = 0;
    for(int i = n-1; i >= 0; i--){
        curSum -= v[i+1];
        leftSum += v[i+1];
        maxn = max(maxn,leftSum-(c-x[i+1]));
        ans = max(ans,curSum-x[i]);
        ans = max(ans,curSum-2*x[i]+maxn);
    }
    return ans;
}

int main(){
    int n; long long c;
    scanf("%d%lld",&n,&c);
    for(int i = 1; i <= n; i++){
        scanf("%lld%lld",&x[i],&v[i]);
        tx[n-i+1] = c-x[i];
        tv[n-i+1] = v[i];
    }
    long long ans = solve(n,c,x,v);
    for(int i = 1; i <= n; i++) x[i] = tx[i], v[i] = tv[i];
    ans = max(ans,solve(n,c,x,v));
    printf("%lld\n",ans);
    return 0;
}
