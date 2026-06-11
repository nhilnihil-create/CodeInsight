#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A, B;
long long K;
int mod = 998244353;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

//long long factorial(long long n) {
//    if (n == 1) {
//        return 1;
//    } else {
//        return  n * factorial(n - 1) % mod;
//    }
//}

long long power(long long a, int n){
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        long long b = power(a, n / 2);
        return 1ll * b * b % mod;
    } else {
        return 1ll * a * power(a, n - 1) % mod;
    }
}

long long inverse(long long a) {
    if (a == 1) {
        return 1;
    }
    return power(a, mod - 2);
}

int main() {
    cin >> N >> A >> B >> K;
    
    if (K < min(A, B)) {
        cout << 1 << endl;
        return 0;
    }
    
    int d = gcd(A, B);
    if (K % d != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<long long> factorial(N + 1), factinv(N + 1);
    factorial[0] = 1; factinv[0] = 1;
    for (int i = 1; i < N + 1; i++) {
        factorial[i] = factorial[i - 1] * i % mod;
        factinv[i] = inverse(factorial[i]);
    }
    
    K /= d; A /= d; B /= d;
    long long ans = 0;
    for (int n = 0; n <= N; n++) {  //nA+mB = Kの解をみつける
       if ((K - n * A) % B != 0) {
            continue;
        } else {
            long long m = (K - n * A) / B;  //NCn * NCmだけ解がある
            if (m > N || m < 0) {
                continue;
            }
            ans += factorial[N] * factorial[N] % mod * factinv[n] % mod * factinv[N - n] % mod * factinv[m] % mod * factinv[N - m] % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}