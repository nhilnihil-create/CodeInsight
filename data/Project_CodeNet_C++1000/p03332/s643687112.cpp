#include<bits/stdc++.h>
using namespace std;
const int mx = 300005;
const int md = 998244353;
int n, t = md - 2;
long long fact[mx] = {1}, a, b, k, u, in[mx], comb[mx], ans;

int main(){
    scanf("%d%lld%lld%lld", &n, &a, &b, &k);
    for(int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % md;
    u = fact[n]; in[n] = 1;
    while(t){
        if(t&1) in[n] = in[n] * u % md;
        u = u * u % md;
        t >>= 1;
    }
    for(int i = n; i > 0; i--) in[i-1] = in[i] * i % md;
    for(int i = 0; i <= n; i++) comb[i] = fact[n] * in[n-i] % md * in[i] % md;
    for(int i = 0; i <= n; i++){
        if((k - a*i) % b == 0){
            long long u = (k - a*i) / b;
            if(0 <= u && u <= n) ans = (ans + comb[i] * comb[u]) % md;
        }
    }
    printf("%lld\n", ans);
}