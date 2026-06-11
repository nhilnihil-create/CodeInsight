#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> T(N, 0);
    for (int i = 1; i < N; i++) {
        T[i] += T[i - 1];
        if (S[i - 1] == 'A' && S[i] == 'C') T[i]++;
    }

    int l, r;
    rep(_, Q) {
        cin >> l >> r;
        cout << T[r - 1] - T[l - 1] << '\n';
    }

    return 0;
}