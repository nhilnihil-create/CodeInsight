#include<bits/stdc++.h>
#define je 1000000007
using namespace std;

int n;
long long su[100005];
long long sum[100005];
long long lsum[100005];
long long rsum[100005];

long long fact[100005];
long long inv[100005];

long long invv(long long x){
    int lft = je - 2;
    long long ret = 1;
    long long gop = x;
    while(lft){
        if(lft & 1){
            ret = (ret * gop) % je;
        }
        gop = (gop * gop) % je;
        lft >>= 1;
    }
    return ret;
}

int main(){
    scanf("%d", &n);
    fact[0] = 1;
    for(int i=1;i<=n;i++){
        fact[i] = (fact[i-1] * i) % je;
        inv[i] = invv(fact[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld", &su[i]);
    }
    for(int i=1;i<=n;i++){
        sum[i] = (sum[i-1] + su[i]) % je;
        lsum[i] = (lsum[i-1] + i * su[i]) % je;
    }
    for(int i=n;i>=1;i--){
        rsum[i] = (rsum[i+1] + (n+1-i) * su[i]) % je;
    }
    long long ans = (fact[n] * ((sum[n] - sum[0] + je) % je)) % je;
    for(int ii=1;ii<n;ii++){
        long long cal1 = (sum[n] - sum[n-ii] + je + sum[ii]) % je;
        long long gop1 = ((fact[n] * inv[ii+1]) % je * fact[ii]) % je;
        long long gap = min(ii, n-1-ii);
        long long cal2 = (sum[n-gap] - sum[gap] + je) % je;
        cal2 = (cal2 * (gap+1)) % je;
        long long cal3 = (lsum[gap] + rsum[n+1-gap]) % je;
        cal2 = (cal2 + cal3) % je;
        cal2 = (cal2 + je - sum[n]) % je;
        long long gop2 = ((fact[n] * inv[ii+2]) % je * fact[ii] * 2) % je;
        long long cal = (cal1 * gop1 + cal2 * gop2) % je;
        ans = (ans + cal) % je;
    }
    printf("%lld\n", ans);
}
