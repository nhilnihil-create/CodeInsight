#include <bits/stdc++.h>

using namespace std;

/*
 * エラトステネスの篩
 *   n 以下の素数を bitset で返す
 */
static bitset<100000 + 1> sieve_of_eratosthenes (long long n) {
    bitset<100000 + 1> prime(0);

    for ( long long i = 2; i <= n; i++ )
        prime.set(i);
    for ( long long i = 2; i <= n; i++ ) {
        if ( prime[i] ) {
            for ( long long j = i * 2; j <= n; j += i ) {
                prime.reset(j);
            }
        }
    }

    return prime;
}

int main (void) {
    bitset<100000 + 1> primes = sieve_of_eratosthenes(100000);
    vector<int> cumsum(100000 + 1, 0);
    for ( int i = 1; i <= 100000; i += 2 ) {
        if ( primes[i] && primes[(i+1)/2] ) {
            cumsum.at(i) = 1;
        }
    }
    for ( int i = 1; i <= 100000; i++ ) {
        cumsum.at(i) += cumsum.at(i-1);
    }

    int Q;
    cin >> Q;
    int l, r;
    for ( int i = 0; i < Q; i++ ) {
        cin >> l >> r;
        cout << cumsum.at(r) - cumsum.at(l-1) << endl;
    }

    return 0;
}
