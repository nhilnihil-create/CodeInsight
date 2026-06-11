#include <iostream>
#include <map>

typedef long long ll;

using namespace std;

int main() {
    ll N, P;
    cin >> N >> P;

    ll p = P;
    map<ll, int> primes;
    for (ll i = 2; i * i <= P; i++) {
        int k = 0;
        while (p % i == 0) {
            p /= i;
            k++;
        }
        if (k > 0) {
            primes[i] = k;
        }
    }
    if (p > 1) {
        primes[p] = 1;
    }

    ll output = 1;
    for (auto p : primes) {
        int k = p.second;
        while (k >= N) {
            output *= p.first;
            k -= N;
        }
    }
    cout << output << endl;

    return 0;
}
