#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    int MAX = 55556;
    vector<int> is_prime(MAX, 1);
    is_prime[0] = 0, is_prime[1] = 0;
    for (int i = 2; i < MAX; ++i) {
        if (!is_prime[i])
            continue;
        for (int j = i * 2; j < MAX; j += i)
            is_prime[j] = 0;
    }

    vector<int> fives;
    rep(i, is_prime.size()) {
        if (is_prime[i] && i % 5 == 1)
            fives.push_back(i);
    }

    rep(i, N) { cout << fives[i] << " "; }
}