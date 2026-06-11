#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int cnt = 0;
map<int, int> mp;

void enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            ++mp[i];
            if (N / i != i) {
                ++mp[N / i];
            }
        }
    }
    return;
}

int main() {
    long long N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    rep(i, 2) enum_divisors(A[i]);

    vector<vector<int>> num(mp.size(), vector<int>(2));
    int i = 0;
    for (auto x : mp) {
        num[i][0] = x.first;
        num[i][1] = x.second;
        ++i;
    }
    reverse(num.begin(), num.end());

    if (N > 2) {
        for (int i = 2; i < N; ++i) {
            rep(j, num.size()) {
                if (A[i] % num[j][0] == 0) ++num[j][1];
            }
        }
    }
    rep(i, num.size()) if (num[i][1] == N || num[i][1] == N - 1) {
        cout << num[i][0] << endl;
        break;
    }
}
