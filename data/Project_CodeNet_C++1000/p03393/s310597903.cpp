#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    vector<vector<bool>> data(N, vector<bool>(26, false));
    data.at(0).at(S.at(0) - 'a') = true;
    for (int i = 1; i < N; i++) {
        data.at(i) = data.at(i - 1);
        data.at(i).at(S.at(i) - 'a') = true;
    }

    bool can = false;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (!data.at(i).at(j)) {
                if (i < N - 1) {
                    if (S.at(i + 1) - 'a' >= j) {
                        continue;
                    }
                }
                can = true;
                char c = 'a' + j;
                S = S.substr(0, i + 1) + c;
                break;
            }
        }
        if (can) {
            break;
        }
    }

    if (can) {
        cout << S << endl;
    }
    else if (S != "zyxwvutsrqponmlkjihgfedcba") {
        char c = S.at(0) + 1;
        cout << c << endl;
    }
    else {
        cout << -1 << endl;
    }
}