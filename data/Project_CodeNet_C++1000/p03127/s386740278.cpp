#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    // int n;
    // cin >> n;
    // priority_queue<int, vector<int>, greater<int> > q;
    // rep(i, n) {
    //     int a;
    //     cin >> a;
    //     q.push(a);
    // }
    // while (q.size() > 1) {
    //     int m = q.top(); // 残っているモンスターのうち体力が最も低いものが攻撃する
    //     q.pop();
    //     rep(i, q.size()) {
    //         int a = q.top();
    //         q.pop();
    //         if (a % m != 0) {
    //             a %= m;
    //             q.push(a);
    //         }
    //     }
    //     q.push(m);
    // }
    // cout << q.top() << endl;
    // 全モンスターの体力の最大公約数が答えになる
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        if (i == 0) continue;
        a[i] = gcd(a[i], a[i-1]);
    }
    cout << a[n-1] << endl;
}