#include <iostream>
#include <vector>
using namespace std;

int MAX_VALUE = 10e5;

vector<bool> make_primes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        for (int j = i * 2; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i].first >> data[i].second;
    }

    vector<bool> is_prime = make_primes(MAX_VALUE);
    vector<int> prime_counter(MAX_VALUE + 1);
    for (int i = 2; i <= MAX_VALUE; ++i) {
        prime_counter[i] = prime_counter[i - 1];
        if (is_prime[i] && is_prime[(i + 1) / 2]) {
            ++prime_counter[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        int ans =
            prime_counter[data[i].second] - prime_counter[data[i].first - 1];
        cout << ans << endl;
    }

    return 0;
}