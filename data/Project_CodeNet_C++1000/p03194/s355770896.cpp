#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int primes[10000001] = {0};

long long maxdiv(long long n, long long p) {
    if (n == 1)
        return p;

    long long a = 2;
    while(p >= a * a) {
        if (p % a == 0)
        {
            p /= a;
            primes[a]++;
        }
        else {
            a++;
        }
    }

    if (p < 10000001)
        primes[p]++;

    long long max = 1;

    for (long long i = 0; i < 10000001; i++) {
        // if (1 <= primes[i]) {
        //     cout << i << " : " << primes[i] << endl;
        // }

        if (n <= primes[i]) {
            max *= pow(i, primes[i] / n);
        }
    }

    return max;
}

int main(void) 
{
    long long n, p;
    cin >> n >> p;

    cout << maxdiv(n, p) << endl;

    return 0;
}