#include <iostream>
#include <string>
using namespace std;

int C[256];

bool check(int N, int ka, int kb, int kc) {
    bool ok = true;
    if (N - ka > 0) {
        ok = ok && (C['a'] == (N - ka + 3 - 1) / 3);
    }
    if (N - kb > 0) {
        ok = ok && (C['b'] == (N - kb + 3 - 1) / 3);
    }
    if (N - kc > 0) {
        ok = ok && (C['c'] == (N - kc + 3 - 1) / 3);
    }
    return ok;
}

int main() {
    string S;
    cin >> S;

    for (int i=0; i<S.size(); i++) {
        C[S.at(i)]++;
    }

    bool ok = check(S.size(), 0, 1, 2) ||
              check(S.size(), 0, 2, 1) ||
              check(S.size(), 1, 0, 2) ||
              check(S.size(), 2, 0, 1) ||
              check(S.size(), 1, 2, 0) ||
              check(S.size(), 2, 1, 0);

    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}