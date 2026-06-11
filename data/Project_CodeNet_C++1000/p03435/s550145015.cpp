#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    vector<vector<int>> c(3, vector<int>(3)) ;

    rep(i,3) {
        rep(j,3) {
            cin >> c.at(i).at(j);
        }
    }

    rep(a1,101) {
        rep(a2,101) {
            rep(a3,101) {
                rep(b1,101) {
                    if ((a1+b1)>100 || (a2+b1)>100 || (a3+b1)>100) continue;
                    if ((a1+b1) != c.at(0).at(0)) continue;
                    if ((a2+b1) != c.at(1).at(0)) continue;
                    if ((a3+b1) != c.at(2).at(0)) continue;
                    rep(b2,101) {
                        if ((a1+b2)>100 || (a2+b2)>100 || (a3+b2)>100) continue;
                        if ((a1+b2) != c.at(0).at(1)) continue;
                        if ((a2+b2) != c.at(1).at(1)) continue;
                        if ((a3+b2) != c.at(2).at(1)) continue;
                        rep(b3,101) {
                            if ((a1+b3)>100 || (a2+b3)>100 || (a3+b3)>100) continue;
                            if ((a1+b3) != c.at(0).at(2)) continue;
                            if ((a2+b3) != c.at(1).at(2)) continue;
                            if ((a3+b3) != c.at(2).at(2)) {
                                continue;
                            } else {
                                cout << "Yes" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
