#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

bool is_prime(const unsigned n) {
    switch (n) {
        case 0:
        case 1:
            return false;
        case 2:
        case 3:
            return true;
    }
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (unsigned i = 5; i * i <= n; i += 6) {
        if (n % i == 0) return false;
        if (n % (i + 2) == 0) return false;
    }
    return true;
}

// void solve() {
// int l, r;
// cin >> l >> r;
// int output = 0;
// for (int i = l; i <= r; i++) {
// if (is_prime(i) && is_prime((i + 1) / 2)) {
// output++;
// }
// }
// cout << output << endl;
// }

int main() {
    int Q;
    cin >> Q;

    int acc = 0;
    vector<int> primes(1e5 + 3, 0);
    for (int i = 1; i <= 100000; i++) {
        if (is_prime(i) && is_prime((i + 1) / 2)) {
            acc++;
        }
        primes[i] = acc;
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << primes[r] - primes[l - 1] << endl;
    }

    return 0;
}
