#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, a, b, k, mod = 998244353, fac[300005], invfac[300005], ans;
int inv(int x){
    int pw = mod - 2, ans = 1;
    while(pw){
        if(pw & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        pw /= 2;
    }
    return ans;
}

int c(int n, int k){
    int tmp = (fac[n] * invfac[k]) % mod;
    return (tmp * invfac[n - k]) % mod;
}

signed main(){
    cin >> n >> a >> b >> k;
    fac[0] = 1;
    for(int i = 1; i <= 300000; i++) fac[i] = (fac[i - 1] * i) % mod;
    for(int i = 0; i <= 300000; i++) invfac[i] = inv(fac[i]);
    for(int i = 0; i <= n; i++){
        int tmp = k - (a * i);
        if(tmp < 0) break;
        if(tmp % b) continue;
        if((tmp / b) > n) continue;
        //cout << n << " " << i << " " << tmp / b << " ";
        ans = (ans + (c(n, i) * c(n, tmp / b))) % mod;
        //cout << ans << "\n";
    }
    cout << ans;
}