#include "bits/stdc++.h"

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // 左にあるblackの個数
    int lBlack = 0;
    // 右にあるwhiteの個数
    int rWhite = count(S.begin(), S.end(), '.');

    int ans = lBlack + rWhite;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '#')
            lBlack += 1;
        else
            rWhite -= 1;
        ans = min(ans, lBlack + rWhite);
    }
    cout << ans << endl;
}