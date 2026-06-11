# include <cstdio>
const long long mod = 1e9+7;
long long inv[100003]={1,1}, fi[100003]={1,1};
int main(){
    int n;
    long long ans = 0, b=1, x;
    scanf("%d",&n);
    for(int i=2; i<=n; ++i){
        inv[i] = inv[mod%i]*(mod-mod/i)%mod;
        fi[i] = (fi[i-1]+inv[i])%mod;
    }
    for(int i=1; i<=n; ++i){
        scanf("%lld",&x);
        ans = (ans + (fi[i]+fi[n-i+1]-1+mod)%mod*x%mod)%mod;
        b = b*i%mod;
    }
    printf("%lld\n",ans*b%mod);
    return 0;
}
