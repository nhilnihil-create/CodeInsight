#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    string S;
    ll K;
    cin >> S >> K;
    rep(i, S.size()) {
        if (S[i] != '1') {
            cout << S[i] << "\n";
            return 0;
        }
        if (K == i + 1) {
            cout << "1\n";
            return 0;
        }
    }
}