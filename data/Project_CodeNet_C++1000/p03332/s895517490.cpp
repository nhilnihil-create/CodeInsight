#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

long long kai[400010];

void init(){
    kai[0] = 1;
    for(int i = 1;i < 400010;i++){
        kai[i] = kai[i-1] * i % MOD;
    }
    return;
}

long long pow_mod(long long n, long long m){
    long long ans = 1;
    while(m > 0){
        if(m & 1) ans = ans * n % MOD;
        n = n*n % MOD;
        m >>= 1;
    }
    return ans;
}

long long combi(int n, int r){
    return (kai[n] * pow_mod(kai[r], MOD-2) % MOD) * pow_mod(kai[n-r], MOD-2) % MOD;
}

int main(){
    int n;
    long long a, b, k;
    cin >> n >> a >> b >> k;

    init();

    long long ans = 0;
    for(int i = 0;i <= n;i++){
        if(k-(a*i) >= 0 && (k-(a*i)) % b == 0 && (k-(a*i)) / b <= n){
            ans = (ans + (combi(n, i) * combi(n, (k-(a*i)) / b)) % MOD) % MOD;
        }
    }

    cout << ans << endl;
    return 0;
}
