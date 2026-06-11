#include "bits/stdc++.h"
using namespace std;
int main() {
    string M = "AKIHABARA";
    int d[4] = {0, 4, 6, 8};
    string S;
    cin >> S;
    if (S.size() < 5 || S.size() > 9) cout << "NO" << endl;
    else {
        for (int i = 0; i < (1 << 4); i++) {
            vector<bool>B(9, true);
            for (int j = 0; j < 4; j++) {
                if (i & (1 << j)) B.at(d[j]) = false;
            }
            string T = "";
            if (B.empty()) {
                T = "KIHBR";
            }
            else {
                for (int j = 0; j < 9; j++) {
                    if (B.at(j)) T.push_back(M.at(j));
                }
                if (S == T) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
        cout << "NO" << endl;
    }
}