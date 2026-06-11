#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)

bool isACGT(char arg) {
    if(arg == 'A' || arg == 'C' || arg == 'G' || arg == 'T') {
        return true;
    } else {
        return false;
    }
}

int main() {
    string S;
    cin >> S;

    ll ans = 0;
    ll cnt = 0;
    REP(i, S.length()) {
        if(isACGT(S[i])) {
            ++cnt;
        } else {
            cnt = 0;
        }
        if(cnt > ans) {
            ans = cnt;
        }
    }

    cout << ans << endl;

    return 0;
}