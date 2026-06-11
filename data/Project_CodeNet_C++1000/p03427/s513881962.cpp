#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int K = S.size();
    bool check = true;
    if (K == 1) {
        cout << S << endl;
        return 0;
    }
    for (int i = 1; i < K; i++) {
        if (S[i] != '9') {
            check = false;
        }
    }
    int top = (S[0] - '0');
    if (check) {
        cout << top + 9 * (K - 1) << endl;
    } else {
        cout << top - 1 + 9 * (K - 1) << endl;
    }
}