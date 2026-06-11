#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int cnt = 0, length = S.size();
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j <= length; j++) {
            bool count = true;
            for (int k = i; k < j; k++) {
                if (S.at(k) != 'A' && S.at(k) != 'T' && S.at(k) != 'G' && S.at(k) != 'C') count = false;
            }
            if (count) cnt = max(cnt, j - i);
        }
    }
    cout << cnt << endl;
}