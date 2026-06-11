#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    string T;
    cin >> S >> T;
    for(int i = 0; i < S.size(); i++) {
        if(S == T) {
            cout << "Yes" << endl;
            return 0;
        }
        S = S[S.size()-1]+S.substr(0,S.size()-1);
    }
    cout << "No" << endl;
}