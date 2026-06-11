#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define MAX_N 200010
long long inv[MAX_N];
long long factorial[MAX_N];
long long inv_factorial[MAX_N];

void GetInv(){
    for (int i = 1; i < MAX_N; i++) {
        if (i == 1) inv[i] = 1;
        else {
            inv[i] = (mod - (mod / i) * inv[mod % i]) % mod;
            if (inv[i] < 0) inv[i] += mod;
        }
    }
}
void GetFactorial(){
    factorial[0] = 1; inv_factorial[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        factorial[i] = factorial[i-1] * i;
        factorial[i] %= mod;
        inv_factorial[i] = inv_factorial[i-1] * inv[i];
        inv_factorial[i] %= mod;
    }
}

int main() {
    GetInv(); GetFactorial();
    int n; cin >> n;
    vector<long long> v(n), sum(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum[i+1] = sum[i] + v[i]; 
    }
    long long ans = factorial[n] * (sum[n] % mod) % mod;
    for (int d = 1; d < n; d++) {
        long long a = (sum[n] - sum[d] + sum[n-d]) % mod;
        long long b = factorial[n] * inv[d+1] % mod;
        ans += a * b % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}