#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// #define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;

int bigger(int a, int b) {
    return a >= b ? a : b;
}

int smaller(int a, int b) {
    return a >= b ? b : a;
}


signed main() {
    int N;
    string A, B, C;

    cin >> N >> A >> B >> C;;

    int ans = 0;
    REP(i, N) {
        int sames = (A.at(i) == B.at(i) ? 1 : 0) + (B.at(i) == C.at(i) ? 1 : 0) + (C.at(i) == A.at(i) ? 1 : 0);
        debug(i);
        debug(sames);
        hyphen();
        if (sames == 3) {
            // 3つ同じ場合は変えなくてOK
            ;
        } else if (sames == 2) {
            // ないのでは?
            ;
        } else if (sames == 1) {
            ans += 1;
        } else {
            ans += 2;
        }
    }

    cout << ans << endl;
}
