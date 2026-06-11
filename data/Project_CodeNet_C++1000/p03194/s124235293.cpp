#include <iostream>
#include <cmath>
using namespace std;

long N, P, i, j, n;

long long pow2(long a, long b) {
    if (b == 0) {
        return 1;
    } else if (b == 1) {
        return a;
    } else if (b % 2 == 0) { //b偶数
        long long tmp = pow2(a, b / 2);
        return tmp * tmp;
    } else {
        long long tmp = pow2(a, (b-1) / 2);
        return tmp * tmp * a;
    }
}

int main(void) {
    cin >> N >> P;
    if (N == 1) {
        cout << P << endl;
        return 0;
    }
    long sqrt_P = sqrt(P);
    long ans = 1;
    //Pを素因数分解
    for (i=2; i<=sqrt_P; i++) {
        n = 0;
        while (P % i == 0) {
            P /= i;
            n++;
        }
        if (n >= N) {
            ans *= pow2(i, n / N);
        }
    }
    
    cout << ans << endl;
    return 0;
}


