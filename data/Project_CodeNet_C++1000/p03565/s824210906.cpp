#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S, S_, T;
    cin >> S >> T;
    S_ = S;

    for (int i = S.length() - 1; i >= 0; i--) {
        for (int j = 0; j < T.length(); j++) {
            if ((S[i] == T[j] || S[i] == '?') &&
                T.length() - j <= S.length() - i && j <= i) {
                bool match = true;
                for (int k = 0; k < T.length(); k++) {
                    if (!(S[i - j + k] == T[k] || S[i - j + k] == '?')) {
                        match = false;
                    }
                }
                if (match) {
                    for (int k = 0; k < T.length(); k++) {
                        S[i - j + k] = T[k];
                    }
                    for (int k = 0; k < S.length(); k++) {
                        if (S[k] == '?') {
                            S[k] = 'a';
                        }
                    }
                    cout << S << endl;
                    return 0;
                }
            }
        }
    }

    cout << "UNRESTORABLE" << endl;

    return 0;
}
