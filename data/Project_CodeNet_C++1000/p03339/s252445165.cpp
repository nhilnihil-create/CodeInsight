#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    vector<int> w(N, 0);
    vector<int> e(N, 0);
    FOR(i, 1, N) {
        w[i] = w[i - 1] + (S[i - 1] == 'W');
    }
    for(int i = N - 2;0 <= i;i--) {
        e[i] = e[i + 1] + (S[i + 1] == 'E');
    }
    int res = IINF;
    REP(i, N) {
        res = min(res, w[i] + e[i]);
    }
    cout << res << endl;
    return 0;
}
