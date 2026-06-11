#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string S;
    cin >> S;
    rep(i, S.size()) {
        char c = S.at(i);
        if (c == '1') cout << '9';
        else if (c == '9') cout << '1';
        else cout << c;
    }
    cout << endl;
}
