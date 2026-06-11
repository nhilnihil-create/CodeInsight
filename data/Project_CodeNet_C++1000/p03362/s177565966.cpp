#include "bits/stdc++.h"

using namespace std;

const int MAX = 55556;

void Main() {
    int N;
    cin >> N;

    vector<bool> isPrime(MAX, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= MAX; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        for (int j = 2; i * j < MAX; ++j) {
            isPrime[i * j] = false;
        }
    }
    vector<int> primes;
    vector<int> primes1mod5;
    for (int i = 2; i <= 55555; ++i) {
        if (isPrime[i] && i % 5 == 1) {
            primes1mod5.push_back(i);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << primes1mod5[i];
    }
    cout << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
