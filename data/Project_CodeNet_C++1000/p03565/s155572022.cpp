#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string S, T;
    cin >> S >> T;
    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());
    rep(i,S.size()-T.size()+1) {
        bool ok = true;
        rep(j,T.size()) {
            if (S.at(i + j) != '?' && S.at(i + j) != T.at(j)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            rep(j,T.size()) S.at(i + j) = T.at(j);
            rep(j,S.size()) if (S.at(j) == '?') S.at(j) = 'a';
            reverse(S.begin(), S.end());
            cout << S << endl;
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;
}

