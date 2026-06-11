#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    string key = "keyence";
    bool yes = true;
    for(int i = 0; i < 7; i++) {
        if(S[i] != key[i]) {
            yes = false;
            break;
        }
    }
    if(yes) {
        cout << "YES";
        return 0;
    }

    yes = true;
    for(int i = 0; i < 7; i++) {
        if(S[N - 1 - i] != key[6 - i]) {
            yes = false;
            break;
        }
    }
    if(yes) {
        cout << "YES";
        return 0;
    }

    for(int i = 0; i < 7; i++) {
        yes = true;
        for(int j = 0; j < i; j++) {
            if(S[j] != key[j]) {
                yes = false;
                break;
            }
        }
        for(int j = N - 1; j >= N - 1 - (6 - i); j--) {
            if(S[j] != key[6 - (N - 1 - j)]) {
                yes = false;
                break;
            }
        }
        if(yes) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
