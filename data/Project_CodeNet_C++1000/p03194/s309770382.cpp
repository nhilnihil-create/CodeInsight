#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> primeFiled(static_cast<unsigned long>((int)sqrt(1e12)) + 100, false);
    vector<long int> prime;
    for (int i = 2; i <= sqrt(1e12); i++) {
        if (!primeFiled[i]) {
            prime.push_back(i);
            for (int j = i; j <= sqrt(1e12); j += i) {
                primeFiled[j] = true;
            }
        }
    }
    long int N, P;
    cin >> N >> P;
    long int temp = P;
    vector<int> primeFactor(prime.size(), 0);
    while (P > 1) {
        bool check = false;
        for (int i = 0; i < prime.size(); ++i) {
            if (P % prime[i] == 0) {
                ++primeFactor[i];
                P /= prime[i];
                check = true;
                break;
            }
        }
        if (!check) break;
    }
    long int answer = 1;
    for (int i = 0; i < primeFactor.size(); ++i) {
        if (primeFactor[i] >= N) {
            for (int j = 0; j < (int)(primeFactor[i] / N); ++j) {
                answer *= prime[i];
            }
        }
    }
    if (N == 1) {
        cout << temp << endl;
    } else {
        cout << answer << endl;
    }
}