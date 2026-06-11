#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, a, b, k, mod = 998244353;

int factorialNumInverse[300003], naturalNumInverse[300003], fact[300003];

void InverseofNumber(int mod) 
{ 
        naturalNumInverse[0] = naturalNumInverse[1] = 1; 
        for (int i = 2; i <= 300000; i++) {
                naturalNumInverse[i] = naturalNumInverse[mod % i] * (mod - mod / i) % mod; 
        }
}

void InverseofFactorial(int mod) 
{ 
        factorialNumInverse[0] = factorialNumInverse[1] = 1; 
        for (int i = 2; i <= 300000; i++) {
                factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % mod;
        }
} 
  
void factorial(int mod) 
{ 
        fact[0] = 1;
        for (int i = 1; i <= 300000; i++) { 
                fact[i] = (fact[i - 1] * i) % mod;
        } 
}

int nCr(int N, int R) { 
        return ((fact[N] * factorialNumInverse[R]) % mod * factorialNumInverse[N - R]) % mod; 
}

signed main() {
	InverseofNumber(mod); 
    InverseofFactorial(mod); 
    factorial(mod);
    int ans = 0;
	cin >> n >> a >> b >> k;
	for(int x = 0; x <= n; x++) {
		int y = (k - a * x) / b;
		if(y >= 0 && y <= n && a * x + b * y == k) {
			ans = (ans + (nCr(n, x) * nCr(n, y)) % mod) % mod;
		}
	}
	cout << ans << '\n';
}