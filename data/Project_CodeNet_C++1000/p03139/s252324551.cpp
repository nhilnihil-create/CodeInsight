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
    int N, A, B;

    cin >> N >> A >> B;

    int max = 0;
    int min = 101;
    FORE(c, 0, N) {
        int cand = A + B + c - N;
        debug(cand);

        if (cand >= 0 && cand <= smaller(A,B)) {
            if (cand > max) {
                max = cand;
            }

            if (cand < min) {
                min = cand;
            }
        }
    }

    cout << max << " " << min << endl;


}
