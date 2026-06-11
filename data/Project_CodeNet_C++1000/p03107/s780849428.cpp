#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string S;
    cin >> S;
    int ans = 0;
    int leftcnt = 0;
    char leftcol;
    rep(i,S.size()) {
        if (leftcnt == 0) {
            leftcol = S.at(i);
            ++leftcnt;
        } else if (leftcnt > 0) {
            if (S.at(i) == leftcol) ++leftcnt;
            else {
                ans += 2;
                --leftcnt;
            }
        }
    }
    cout << ans << endl;
}
