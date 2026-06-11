#include <bits/stdc++.h>
using namespace std;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
 
int main() {
int n;
cin >> n;
int m;
cin >> m;
int a;
cin >> a;
if(n>a || n+m<a)cout << "NO" << endl;
  else {cout << "YES" << endl;}
}