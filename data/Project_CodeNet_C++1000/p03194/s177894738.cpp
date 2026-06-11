#include<iostream>
#include<math.h>
using namespace std;

long N, P;

void eratos(long primes[], long size) {
    for (long i=1; i<size; i++) {
        if (primes[i]==1) {
            long t = 1;
            while (i+t*(i+1)<size) {
                primes[i+t*(i+1)] = 0;
                t += 1;
            }
        }
    } 
}

void prime_factorization(long fact[], long primes[], long size) {
    long d = P;
    for (long i=1; i<size; i++) {
        if (primes[i]==1) {
            long tmp = pow((i+1),N);
            while (d%tmp ==0) {
                fact[i] += 1;
                d /= tmp;
            }
        }
        if (d==0) {
            return;
        }
    }
}

long mul_vec(long fact[], long size) {
    int gcd = 1;
    for (long i=1; i<size; i++) {
        if (fact[i]>0) {
            gcd *= pow(i+1, fact[i]);
        }
    }
    return gcd;
}

int main() {
    cin >> N >> P;
    if (N==1) {
        cout << P << endl;
        return 0;
    }

    long n = ceil(pow(P, 1.0/N));

    long primes[n]; // Binary for the prime indices
    primes[0] = 0;
    for (long i=1; i<n; i++) {
        primes[i] = 1;
    }
    eratos(primes, n);

    long fact[n]; // Prime factorization of P^(1/N)
    for (long i=0; i<n; i++) {
        fact[i] = 0;
    }
    prime_factorization(fact, primes, n);

    long gcd = mul_vec(fact, n);
    cout << gcd << endl;
    return 0;
}