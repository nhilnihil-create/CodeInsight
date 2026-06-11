#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    map<int, int> alphabet;
    string S;
    cin >> S;

    for (int i = 0; i < S.length(); i++) {
        alphabet[S[i]]++;
    }

    if (S.size() != 26) {
        for (int i = 'a'; i <= 'z'; i++) {
            if (alphabet[i] == 0) {
                S += i;
                break;
            }
        }
    } else {
        for (int i = 25; i >= 0; i--) {
            for (int j = S[i] + 1; j <= 'z'; j++) {
                if (alphabet[j] == 0) {
                    S[i] = j;
                    S = S.substr(0, i + 1);
                    cout << S << endl;
                    return 0;
                }
            }
            alphabet[S[i]]--;
        }
        cout << -1 << endl;
        return 0;
    }
    cout << S << endl;

    return 0;
}
