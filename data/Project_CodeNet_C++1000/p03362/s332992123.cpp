#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    ll MAX = 55556;
    vector<int> is_prime(MAX, 1);
    is_prime[0] = 0, is_prime[1] = 0;
    for (int i = 2; i < MAX; ++i) {
        if (!is_prime[i])
            continue;
        for (int j = 2 * i; j < MAX; j += i)
            is_prime[j] = 0;
    }

    rep(i, MAX) {
        if (is_prime[i] && i % 5 == 1) {
            cout << i << " ";
            N--;
            if (N == 0)
                break;
        }
    }
}