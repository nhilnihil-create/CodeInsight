#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int m, k;
    cin >> m >> k;
    if (k >= (1 << m)) {
        puts("-1");
        return 0;
    }
    if (m == 0) {
        printf("0 0\n");
        return 0;
    }
    if (m == 1) {
        if (k == 0)
            printf("0 0 1 1\n");
        else
            puts("-1");
        return 0;
    }
    vector<int> half;
    for (int i = 0; i < (1 << m); i++) {
        if (i == k) continue;
        cout << i << " ";
        half.push_back(i);
    }
    cout << k << " ";
    reverse(half.begin(), half.end());
    for (int i : half) {
        cout << i << " ";
    }
    cout << k << endl;
}