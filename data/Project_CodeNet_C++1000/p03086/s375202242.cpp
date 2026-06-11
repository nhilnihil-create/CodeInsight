#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

bool isAcgtStr(string str) {
    bool isAcgtStr = true;
    string acgt = "ACGT";
    for (char alphabet : str) {
        if (find(acgt.begin(), acgt.end(), alphabet) == acgt.end()) isAcgtStr = false;
    }
    return isAcgtStr;
}

int main() {
    string S;
    cin >> S;

    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        for (int j = 1; j <= S.size() - i; j++) {
            string subS = S.substr(i, j); // 部分文字列
            if (isAcgtStr(subS)) ans = max(ans, (int)subS.size());
        }
    }

    cout << ans << endl;

    return 0;
}
