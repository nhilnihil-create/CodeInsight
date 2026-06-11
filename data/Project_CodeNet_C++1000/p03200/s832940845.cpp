#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    ll output = 0;
    ll now = 0;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'B') {
            now++;
        } else {
            output += now;
        }
    }

    cout << output << endl;

    return 0;
}
