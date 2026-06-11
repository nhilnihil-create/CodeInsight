#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S, T;
    cin >> S >> T;
    bool check = 0;
    for(int i = 0; i < S.size(); i++) {
        check = 1;
        for(int j = 0; j < S.size(); j++) {
            if(T.at(j) != S.at((i + j)%S.size())) {
                check = 0;
                break;
            }
        }
        if(check) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;


    return 0;
}