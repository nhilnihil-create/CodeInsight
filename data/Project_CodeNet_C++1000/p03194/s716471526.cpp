#include <iostream>
#include <cmath>
#include <map>
#include <utility>
#include <list>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define LL long long

bool isPrime(LL a) {
    for (LL i=2; i <= sqrt(a); i++){
        if (a % i == 0) return false;
    }
    return true;
}

LL ipow(LL base, LL exp) {
    LL result = 1;
    while(true) {
        if (exp & 1) result *= base;
        exp >>= 1;
        if (!exp) break;
        base *= base;
    }

    return result;
}

int nDividable(LL &a, LL b) {
    if (b == 1) return 0;
    int divided = 0;
    while (a % b == 0) {
        //cout << b << endl;
        divided++;
        a /= b;
    }
    return divided;
}

int main() {
    LL n, p;
    cin >> n >> p;

    LL gcd = 1;
    for (LL i=1; i <= sqrt(p); i++){
        LL q = p;

        int d1 = 0, d2 = 0;
        if (isPrime(i)) d1 = nDividable(q, i);
        if (p % i == 0 && isPrime(p / i)) d2 = nDividable(q, p / i);
 
        if (d1 != 0) gcd *= ipow(i, d1 / n);
        if (d2 != 0) gcd *= ipow(p / i, d2 / n);

        //cout << i << endl;
        p = q;
    }

    cout << gcd << endl;

    return 0;
}
