#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    string S;
    cin >> S;
    int minDiff = 10000;
    for (int i = 0; i < S.size() - 2; i++) {
        string subS;
        subS = S.substr(i, 3);
        int diff = abs(753 - stoi(subS));
        minDiff = min(minDiff, diff);
    }

    cout << minDiff << endl;

    return 0;
}
