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

    // YYMM
    bool isYYMM = true;
    if (stoi(S.substr(2, 2)) < 1 || 12 < stoi(S.substr(2, 2))) {
        isYYMM = false;
    }


    // MMYY
    bool isMMYY = true;
    if (stoi(S.substr(0, 2)) < 1 || 12 < stoi(S.substr(0, 2))) {
        isMMYY = false;
    }

    if(isYYMM && isMMYY) {
        cout << "AMBIGUOUS" << endl;
    } else if(isYYMM) {
        cout << "YYMM" << endl;
    } else if(isMMYY) {
        cout << "MMYY" << endl;
    } else {
        cout << "NA" << endl;
    }

    return 0;
}
