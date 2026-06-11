#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    string S, T;
    cin >> S >> T;
    char to[26];
    for(int i = 0; i < 26; i++) to[i] = '-';

    for(int i = 0; i < S.size(); i++) {
        if(to[(int)S[i] - (int)'a'] != '-') {
            if(to[(int)S[i] - (int)'a'] != T[i]) {
                cout << "No\n";
                return 0;
            }
        }
        to[(int)S[i] - (int)'a'] = T[i];
    }
    sort(to, to + 26);
    for(int i = 25; i >= 1; i--) {
        if(to[i] == '-') break;
        if(to[i - 1] == to[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}