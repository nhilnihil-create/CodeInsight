#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    string S, T; cin >> S >> T;
    int N = S.size();
    int M = T.size();
    
    if (N < M) {
        cout << "UNRESTORABLE\n";
        return 0;
    }

    bool T_found = false;
    for (int i = N - M; 0 <= i; i--) {
        bool found = true;
        rep(j, M) {
            if (S[i + j] == '?') continue;
            if (S[i + j] != T[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            T_found = true;
            rep(j, M) S[i + j] = T[j];
            break;
        }
    }
    if (!T_found) {
        cout << "UNRESTORABLE\n";
        return 0;
    }

    rep(i, N) {
        if (S[i] == '?') S[i] = 'a';
    }
    cout << S << '\n';

    return 0;
}