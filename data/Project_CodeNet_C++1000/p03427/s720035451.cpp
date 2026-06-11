#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    if(S.size() == 1) {
        cout << S << endl;
        return 0;
    }

    for(int i = 1; i < S.size(); i++) {
        if(S.at(i) != '9') {
            break;
        }
        if(i == S.size() - 1) {
            cout << 9*S.size() - 9 + S.at(0) - '0' << endl;
            return 0;
        }
    }

    cout << 9*S.size() - 9 + S.at(0) - '0' - 1 << endl;


    return 0;
}