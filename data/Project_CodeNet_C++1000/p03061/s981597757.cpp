#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= n; i++)

int n;
vector<int> a;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int l(int i) { // a[1]...a[i-1]のgcd
    if (i == 1) return  a[i];
    return gcd(l(i-1), a[i-1]);
}

int r(int i) { // a[i+1]...a[n]のgcd
    if (i == n-1) return  a[i+1];
    return gcd(a[i+1], r(i+1));
}

int m(int i) { // a[1]...a[n]のうちa[i]を除いた部分のgcd
    if (i == 1) return r(i);
    if (i == n) return l(i);
    return gcd(l(i), r(i));
}

int main() {
    cin >> n;
    a.resize(n+1);
    rep(i, n) {
        // if (i == 0) continue;
        cin >> a[i];
    }
    int max_v = 0;

    vector<int> l(n+1), r(n+1), m(n+1);
    for (int i = 2; i <= n; i++) {
        l[i] = gcd(l[i-1], a[i-1]);
    }
    for (int i = n-1; i >= 1; i--) {
        r[i] = gcd(a[i+1], r[i+1]);
    }
    // スッキリと書けるけど逆にわかりづらいかも
    // rep(i, n) {
    //     int j = n-i+1;
    //     if (i == 1) {
    //         l[i] = 0;
    //         r[j] = 0;
    //     } else {
    //         l[i] = gcd(l[i-1], a[i-1]);
    //         r[j] = gcd(a[j+1], r[j+1]);
    //     }
    // }
    rep(i, n) {
        // if (i == 1) m[i] = r[i];
        // else if (i == n) m[i] = l[i];
        // else m[i] = gcd(l[i], r[i]);
        m[i] = gcd(l[i], r[i]);
        max_v = max(m[i], max_v);
    }
    // for (int i = 1; i <= n; i++) {
    //     // max_v = max(m(i+1), max_v);
    //     // max_v = max(m[i], max_v);
    // }
    printf("%d\n", max_v);
}