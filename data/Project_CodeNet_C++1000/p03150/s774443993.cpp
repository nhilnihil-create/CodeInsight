#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    for(int i = 0; i <= 7; i++) {
        if("keyence" == S.substr(0,i) + S.substr(S.size() - 7 + i, 7 - i)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}