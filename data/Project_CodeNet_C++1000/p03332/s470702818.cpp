#include <bits/stdc++.h>

using namespace std;



const int MAXN = 1e5 * 3 + 5;
const int mod = 998244353;

long long fakt[MAXN];

int n;
long long a, b, k;
long long sol = 0;


int mul (int a, int b) {
    return ((long long) a * b) % mod;
}
int add (int a, int b) {
    a+=b;
    if (a >= mod) return a-mod;
    return a;
}
int pow(int baza, int potencija) {
    int r = 1, a = baza, x = potencija;
    while (x) {
        if (x % 2 == 1) {
            r = mul(r,a);
        }
        a = mul(a,a);
        x/=2;
    }
    return r;
}
int divi (int a, int b) {
    return mul(a, pow(b,mod-2));
}

int main () {
    fakt[0] = 1;
    for (int i = 1 ; i < MAXN - 2; i++) {
        fakt[i] = mul(fakt[i-1],i);
    }
    cin >> n >> a >> b >> k;
    for (int i = 0  ; i <= n ; i ++) {
        long long A = a * i;
        if (A > k) break;
        if ((k - A) % b == 0 ) {
            //cout << "PROV: " <<A << " " << B;
            int j = (k-A) / b;
            if (j <= n) sol = add(sol , mul (divi (fakt[n] , mul(fakt[i] ,fakt[n-i] ) ) , divi (fakt[n] , mul(fakt[j] , fakt[n-j] ) ) ) );
        }
        else {
            continue;
        }
     }
    cout << sol;

    return 0;
}


