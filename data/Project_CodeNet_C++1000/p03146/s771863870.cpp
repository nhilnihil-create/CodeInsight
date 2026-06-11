#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int f(int n) {
    if (n % 2 == 0) return n / 2;
    else return 3 * n + 1;
}

int main() {
    int s;
    cin >> s;
    // int n = 1e6+1;
    // vector<int> a(n);
    int prev = s;
    set<int> m;
    m.insert(s);
    for (int i = 2; ; i++) {
        prev = f(prev);
        if (m.count(prev)) {
            cout << i << "\n";
            break;
        } else {
            m.insert(prev);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     if (i == 1) {
    //         a[i] = s;
    //     } else {
    //         a[i] = f(a[i-1]);
    //         for (int j = 1; j < i; j++) {
    //             if (a[j] == a[i]) {
    //                 cout << i << endl;
    //                 goto out;
    //             }
    //         }
    //     }
    // }
    // out:
    return 0;
}