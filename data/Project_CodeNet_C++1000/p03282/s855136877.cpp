#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S;
    ll K;
    cin >> S >> K;
    int cnt1;
    rep(i,S.size()) {
        if (S.at(i) != '1') {
            cnt1 = i;
            break;
        } else if (i == S.size() - 1) {
            cnt1 = S.size();
        }
    }
    if (K <= cnt1) {
        cout << 1 << endl;
    } else {
        cout << S.at(cnt1) << endl;
    }
}
