#include <iostream>
#include <cmath>
using namespace std;

long N, P, i, j, n;

int main(void) {
    cin >> N >> P;
    if (N == 1) {
        cout << P << endl;
        return 0;
    }

    long ans = 1;
    //Pを素因数分解
    for (i=2; i*i<=P; i++) {
        n = 0;
        while (P % i == 0) {
            P /= i;
            n++;
        }
        if (n >= N) {
            ans *= pow(i, n / N);
        }
    }
    
    cout << ans << endl;
    return 0;
}


