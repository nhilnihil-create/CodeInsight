#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    string S;
    string T;

    cin >> S >> T;

    vector<string> ress = {};

    bool flg = false;
    for (int i = 0; i < S.size(); i++) {
        if (i + T.size() > S.size()) break;

        string S2 = S;
        bool is_match = true;
        for (int j = 0; j < T.size(); j++) {
            if (S.at(i + j) == T.at(j) || S.at(i + j) == '?') {
                S2.at(i + j) = T.at(j);
            } else {
                is_match = false;
                break;
            }
        }
        if (is_match) {
            for (int i = 0; i < S.size(); i++) {
                if (S2.at(i) == '?') S2.at(i) = 'a';
            }
            ress.push_back(S2);
        }
    }
    if (ress.size() == 0) {
        cout << "UNRESTORABLE" << endl;
    } else {
        sort(ress.begin(), ress.end());
        cout << ress[0] << endl;
    }
}