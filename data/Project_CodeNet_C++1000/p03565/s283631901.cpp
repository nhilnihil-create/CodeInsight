#include <bits/stdc++.h>
using namespace std;
string S, T;
string answer = "UNRESTORABLE";
bool exists = false;

int main() {
    cin >> S >> T;
    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());

    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < T.size(); j++) {
            int count = 0;
            if (S.at(i) == T.at(j) || S.at(i) == '?') {
                count++;
                // Tのjより前の処理
                // 入りきらない場合
                if (i < j) break;
                for (int k = 1; k <= j; k++) {
                    if (S.at(i-k) == '?' || S.at(i-k) == T.at(j-k)) count++;
                }
                // Tのjより後の処理
                // 入りきらない場合
                if (S.size() - (i + 1) < T.size() - (j + 1)) break;
                
                for (int l = 1; l <= T.size() - (j+1); l++) {
                    if (S.at(i+l) == '?' || S.at(i+l) == T.at(j+l)) count++;
                }
                
                if (count == T.size()) {
                    for(int m = 0; m < T.size(); m++) {
                        S.at(i - j + m) = T.at(m);
                    }
                    exists = true;
                    break;
                }
            }
        }
        if (exists) break;
    }
    if (exists) {
        for(int i = 0; i < S.size(); i++) {
            if (S.at(i) == '?') S.at(i) = 'a';
        }
        reverse(S.begin(), S.end());
        answer = S;
    }

    cout << answer << endl;

    return 0;
}