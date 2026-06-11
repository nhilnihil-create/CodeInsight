#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S, T;
    cin >> S >> T;
    int N = S.length();

    map<char, char> pair;
    for (int i = 0; i < N; i++) {
        if (pair[T[i]] == NULL) {
            pair[T[i]] = S[i];
        } else if (pair[T[i]] != S[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    map<char, int> check;
    for (auto c : pair) {
        check[c.second]++;
        if (check[c.second] >= 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
