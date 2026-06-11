#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep2(i,a,n) for (int i = a; i < n; i++)
using namespace std;

int Q;
int sum[100002]; // sum[i] -> iまでの数で2017に似た数の総数を格納する
vector<pair<int, int>> lr;

bool is_prime(int n) {
    bool flag = true;;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

void input() {
    cin >> Q;
    rep(i, Q) {
        int l, r; cin >> l >> r;
        lr.push_back({l, r});
    }
}

void solve() {
    memset(sum, 0, sizeof(sum));
    sum[0] = 0; sum[1] = 0; sum[2] = 0; sum[3] = 1; sum[4] = 1;

    for (int i = 5; i <= 100000; i++) {
        if (i % 2 == 0) {
            sum[i] = sum[i - 1];
            continue;
        }
        if (is_prime(i) && is_prime((i + 1) / 2)) {
            sum[i] = sum[i - 1] + 1;
        } else {
            sum[i] = sum[i - 1];
        }
    }


    for (auto query : lr) {
        printf("%d\n", sum[query.second + 1] - sum[query.first - 1]);
    }

}
int main() {
    input();
    solve();
    return 0;
}
