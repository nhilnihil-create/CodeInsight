#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const string YES = "YES";
const string NO = "NO";

void solve(std::string S) {
    string keyence = "keyence";
    if (S == keyence) {
        cout << "YES" << endl;
        return;
    }
    for (ll i = 0; i < S.length(); i++) {
        for (ll j = i + 1; j < S.length(); j++) {
            string tmpS = S;
            tmpS.erase(i, j - i);
            if (tmpS == keyence) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int main() {
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
