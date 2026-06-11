#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string S; cin >> S;
    int N = S.size();
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    int L = 0, R = N-1;
    int cnt = 0;
    while (L < R) {
        if (S[L] == S[R]) {
            L++, R--;
            continue;
        }
        cnt++;
        if (S[L] == 'x') {
            L++;
            continue;
        }
        if (S[R] == 'x') {
            R--;
            continue;
        }
        cout << -1 << endl;
        return 0;
    }
    cout << cnt << endl;
}
