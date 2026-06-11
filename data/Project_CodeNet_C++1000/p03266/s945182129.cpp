#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    auto f = [](long long x) {
        return x * x * x;
    };

    long long N, K; cin >> N >> K;
    if (K & 1)
        cout << f(N/K) << "\n";
    else
        cout << f(N/K) + f((N/(K/2)) - (N/K)) << "\n";
}