#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define pi 3.14159265358979323
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int a, b, k;
    cin >> a >> b >> k;
    bool odd = false;
    if (k % 2 == 1) {
        odd = true;
        k--;
    }
    k /= 2;
    rep(i, k) {
        if (a % 2 == 1) {
            a--;
        }
        a -= a / 2;
        b += a;
        if (b % 2 == 1) {
            b--;
        }
        b -= b / 2;
        a += b;
    }
    if (odd) {
        if (a % 2 == 1) {
            a--;
        }
        a -= a / 2;
        b += a;
    }
    cout << a << " " << b << endl;
}