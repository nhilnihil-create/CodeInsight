#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S;
    cin >> S;
    int ans = 0;
    int cnt = 0;
    rep(i,S.size()) {
        if (S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'G' || S.at(i) == 'T') {
            ++cnt;
        } else {
            ans = max(ans, cnt);
            cnt = 0;
        }
        if (i == S.size() - 1) ans = max(ans, cnt);
    } 
    cout << ans << endl;
}
