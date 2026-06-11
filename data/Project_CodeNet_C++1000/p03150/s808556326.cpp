#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string S;
    cin >> S;
    
    bool judge = false;
    rep(i, S.size()) for (int j = i - 1; j < S.size(); ++j) {
        string str = "";
        for (int k = 0; k < i; ++k) str += S[k];
        for (int k = j + 1; k < S.size(); ++k) str += S[k];
        if (str == "keyence") judge = true;
    }
    if (judge) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
