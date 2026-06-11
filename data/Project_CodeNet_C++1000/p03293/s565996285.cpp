#include<iostream>
using namespace std;

int main() {
    string S, T; cin >> S >> T;
    bool canMatch = false;
    for (int i = 0; i < S.size(); i++) {
        if (S == T) {
            canMatch = true;
        }
        S = S[S.size() - 1] + S.substr(0, S.size() - 1);
    }
    if (canMatch) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
