// 7/3
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> A(N + 1);
    A[0] = 0;
    A[1] = 0;
    for (int i = 1; i < N; i++) {
        if (S[i-1]=='A' && S[i]=='C') {
            A[i+1] = A[i] + 1;
        } else {
            A[i+1] = A[i];
        }
    }

    // rep(i, N+1) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;

    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << A[r] - A[l] << endl;
    }
}