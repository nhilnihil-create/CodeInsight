#include <iostream>
#include <cmath>
#include <map>
typedef long long ll;

using namespace std;

int main() {
    ll N, P, tmp;
    cin >> N >> P;
    map<ll, int> prime;
    tmp = P;
    for (ll p = 2; p * p <= P; p++) {
        int count = 0;
        while (tmp % p == 0) {
            tmp /= p;
            count++;
        }
        if (count != 0) {
            prime[p] = count;
        }
    }
    if (tmp > 1) {
        prime[tmp] = 1;
    }

    if (N == 1) {
        cout << P << endl;
        return 0;
    }
    ll gcd = 1;
    for (auto& p: prime) {
        if (p.second >= N) {
            gcd *= pow(p.first, (int)(p.second / N));
        }
    }
    cout << gcd << endl;
	return 0;
}