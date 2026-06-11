#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

vector<bool> Eratosthenes(int n) {
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!prime[i]) continue;
        for (int j = 2; i * j <= n; j++) {
            prime[i * j] = false;
        }
    }
    return prime;
}

int main() {
    int N; cin >> N;

    auto primes = Eratosthenes(55556);
    vector<int> ans;
    REP(i, 2, primes.size()) {
        if (primes[i] && i % 5 == 1) {
            ans.push_back(i);
        }
        if (ans.size() == N) break;
    }

    for (auto a : ans) cout << a << " ";
    cout << endl;
    return 0;
}