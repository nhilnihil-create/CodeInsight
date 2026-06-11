#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int count = S.size() - T.size() + 1;
    vector<string> ans;

    rep(i, count) {
        bool match = true;
        rep(j, T.size()) {
            if(S[j+i] != '?' && S[j+i] != T[j]) {
                match = false;
                break;
            }
        }
        if(match) {
            string tmp;

            rep(j, S.size()) {
                if(j >= i && j < i + T.size()) {
                    tmp += T[j - i];
                } else {
                    if(S[j] == '?')
                        tmp += "a";
                    else
                        tmp += S[j];
                }
            }
            ans.push_back(tmp);
        }
    }

    if(ans.empty()) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    } else {
        sort(ans.begin(), ans.end());
        cout << ans[0] << endl;
    }

    return 0;
}

