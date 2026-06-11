#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
    string S, T; cin >> S >> T;
    vector<char> v(T.size());
    vector<char> tmp(T.size()+1);
    for (int i = 0; i < T.size(); i++) v.at(i) = T.at(i);
    for (int i = 0; i < T.size(); i++) {
        bool flag = true;
        for (int j = 0; j < T.size(); j++) {
            if (S.at(j) != v.at(j)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        }
        tmp.at(0) = v.at(T.size()-1);
        for (int j = 0; j < T.size(); j++) {
            tmp.at(j+1) = v.at(j);
            v.at(j) = tmp.at(j);
        }
    }
    cout << "No" << endl;
}