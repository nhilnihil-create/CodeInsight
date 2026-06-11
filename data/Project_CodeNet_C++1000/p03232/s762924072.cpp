#include<iostream>
using namespace std;


long long mod = 1e9+7;
long long N, A[100000];
long long invs[100001], invs_sum[100001];

long long pow(long long a, long long x){
    if(x == 0){
        return 1;
    }else if(x == 1){
        return a % mod;
    }
    a %= mod;
    return pow(a*a%mod, x/2) * ((x%2)?a:1)%mod;
}

long long inv(long long x){
    return pow(x, mod-2) % mod;
}

long long fac(long long n){
    if(n == 0){
        return 1;
    }
    return n % mod * fac(n-1) % mod;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= 100000; i++){
        invs[i] = inv(i);
        invs_sum[i] = invs_sum[i-1] + invs[i];
    }

    long long ans = 0;
    for(int j = 0; j < N; j++){
        long long p = invs_sum[N-j] + invs_sum[j+1] + (mod - 1);
        long long tmp = (A[j] % mod) * (p % mod) % mod;
        ans += tmp;
        ans %= mod;
    }
    ans *= fac(N);
    ans %= mod;
    cout << ans << endl;
    
    
}
