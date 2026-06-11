#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;





void one_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    int m = 0, M = 0;
    for (auto& el : a) {
        cin >> el;
        m = min(m, el);
        M = max(M, el);
    }
    if (m == 0) {
        cout << n - 1 << "\n";
        for (int i = 1; i < n; ++i) {
            cout << i << " " << i + 1 << "\n";
        }
        return;
    }
    if (M == 0) {
        cout << n - 1 << "\n";
        for (int i = 0; i + 1 < n; ++i) {
            cout << n - i  << " " << n - i - 1 << "\n";
        }
        return;
    }
    if (M > abs(m)) {
        cout << n + n - 1 << "\n";
        int i = 1;
        for (i; i <= n; ++i) {
            if (a[i - 1] == M) {
                break;
            }
        }
        for (int j = 0; j < n; ++j) {
            cout << i << " " << j + 1 << "\n";
        }
        for (int i = 1; i < n; ++i) {
            cout << i << " " << i + 1 << "\n";
        }
    } else {
        cout << n + n - 1 << "\n";
        int i = 1;
        for (i; i <= n; ++i) {
            if (a[i - 1] == m) {
                break;
            }
        }
        for (int j = 0; j < n; ++j) {
            cout << i << " " << j + 1 << "\n";
        }
        for (int i = 0; i + 1 < n; ++i) {
            cout << n - i  << " " << n - i - 1 << "\n";
        }
    }

}


int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);


    int t = 1;
//    cin >> t;
    while (t--) {
        one_case();
    }

    return 0;
}
