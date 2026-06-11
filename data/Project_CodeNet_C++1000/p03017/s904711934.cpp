#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, A, B, C, D;
    string S;

    cin >> N >> A >> B >> C >> D >> S;
    A--, B--, C--, D--;

    bool two_shape = false;
    for (int i=A; i<=C-1; i++) {
        if (S[i]=='#' && S[i+1]=='#') two_shape = true;
    }
    for (int i=B; i<=D-1; i++) {
        if (S[i]=='#' && S[i+1]=='#') two_shape = true;
    }

    bool three_comma = false;
    for (int i=B-1; i<=min(D-1, N-3); i++) {
        if (S[i]=='.' && S[i+1]=='.' && S[i+2]=='.') three_comma = true;
    }

    string ans = "Yes";
    if (two_shape) ans = "No";
    if (C > D && !(three_comma)) ans = "No";
    cout << ans << endl;

    return 0;
}