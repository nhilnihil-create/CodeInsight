#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 100000000;

int main() {
    string S;
    ll K;
    cin >> S >> K;

    int cnt = 0;
    char word = ' ';
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '1') {
            cnt++;
        } else {
            word = S[i];
            break;
        }
    }

    if (word == ' ') {
        cout << 1 << endl;
    } else {
        if (K <= cnt) {
            cout << 1 << endl;
        } else {
            cout << word << endl;
        }
    }
    return 0;
}
