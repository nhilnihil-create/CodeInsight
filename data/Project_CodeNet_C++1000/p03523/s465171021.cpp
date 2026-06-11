#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long ll;

int main() {
    string S, T = "AKIHABARA";
    cin >> S;
    int i = 0;
    rep(j, 9) {
        if (S[i] == T[j]) {
            i++;
            continue;
        }
        if (T[j] == 'A') {
            continue;
        }
        cout << "NO\n";
        return 0;
    }
    if (i == S.size()) cout << "YES\n";
    else cout << "NO\n";
}