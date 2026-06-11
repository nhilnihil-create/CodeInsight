#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int cnt[110] = {};

// n - 1以上の数がある個数
int num(int n) {
    int res = 0;
    for (int i = 0; i < 110; ++i) {
        if (cnt[i] >= n - 1) res++;
    }

    return res;
}

void prime_factor(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i != 0) continue;

        int num = 0;

        while (n % i == 0) {
            ++num;
            n /= i;
        }

        cnt[i] += num;
    }

    if (n != 1) cnt[n]++;
}

int main() {

    int n; cin >> n;

    for (int i = 1; i <= n; ++i) {
        prime_factor(i);
    }

    int ans = num(75)
            + num(25) * (num(3) - 1)
            + num(15) * (num(5) - 1)
            + num(5) * (num(5) - 1) * (num(3) - 2) / 2;

    cout << ans << endl;
}