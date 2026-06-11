#include<iostream>
using namespace std;

long long N, A, B;
long long K;
long long mod = 998244353;
long long fac_memo[300001], fac_inv_memo[300001], C_memo[300001];


long long pow(long long a, long long x){
    a %= mod;
    if(x == 0){
        return 1;
    }
    long long tmp = pow(a * a % mod, x / 2);
    return ((x%2)? a : 1LL) * tmp % mod;  
}

long long inv(long long x){
    return pow(x % mod, mod - 2);
}

long long fac(long long n){
    n %= mod;
    if(fac_memo[n] != 0){
        return fac_memo[n];
    }
    if(n == 0){
        return fac_memo[0] = 1LL;
    }
    return fac_memo[n] = n * fac(n-1) % mod;
}

long long C(long long n, long long r){
    return fac(n) * fac_inv_memo[n-r] % mod * fac_inv_memo[r] % mod;
}

int main(){
    cin >> N >> A >> B >> K;
    long long ans = 0;
    fac(300000);
    for(int i = 0; i <= N; i++){
        fac_inv_memo[i] = inv(fac_memo[i]);
    }
    for(int a = 0; a <= N; a++){
        if((K - a * A) % B != 0 || (K - a * A < 0)){
            continue;
        }
        int b = (K - a * A) / B;
        if(b > N){
            continue;
        }
        ans += C(N, a) * C(N, b) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}
