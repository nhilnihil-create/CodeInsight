#include "bits/stdc++.h"

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    bool ans = true;
    map<char, char> ma, ima;

    for (int i = 0; i < S.size(); ++i) {
        char s = S[i], t = T[i];
        if (ma.count(s)) if (ma[s] != t) ans = false;
        if (ima.count(t)) if (ima[t] != s) ans = false;
        ma[s] = t;
        ima[t] = s;
    }
    cout << (ans ? "Yes" : "No") << endl;
}