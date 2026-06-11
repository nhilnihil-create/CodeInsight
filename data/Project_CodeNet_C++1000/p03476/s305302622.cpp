// 6/2
// 2-6-4. 素数のこすう
// エラトステネスの篩
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

// const int MAX_N = 1000000;

vector<int> prime;  // i番目の素数
vector<bool> is_prime;  // iが素数かどうか

void sieve(int n) {
    // 一旦全ての数字を素数に。
    prime.resize(n, 0);
    is_prime.resize(n + 1, true);

    // 0, 1は素数では無い。
    is_prime[0] = is_prime[1] = false;

    int p = 0;

    for (int i = 2; i < n; i++) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // return p;
}

int main() {
    int Q;
    cin >> Q;

    sieve(1e5 + 1);
    // cout << "here?" << endl;
    vector<int> numx(1e5 + 1, 0);  // numx[i] = 1までの2017に似た数の個数

    numx[0] = 0;
    numx[1] = 0;

    for (int i = 3; i <= 1e5; i += 2) {
        numx[i] = numx[i - 2];
        if (is_prime[i] && is_prime[(i + 1) / 2]) numx[i] += 1;
    }

    // cout << "here?2" << endl;

    vector<int> ans;

    rep(i, Q) {
        int l, r;
        cin >> l >> r;

        if (l == 1) {
            ans.push_back(numx[r]);
        } else {
            ans.push_back(numx[r] - numx[l - 2]);
        }
    }

    for (auto a : ans) cout << a << endl;
}
