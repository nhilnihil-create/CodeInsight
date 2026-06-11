#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL MOD = 1e9+7;

int main() {
    int N, A, B, C;
    vector<int> T(4, 0);
    cin >> N >> T[0] >> T[1] >> T[2];
    vector<int> l(N);
    REP(i, N) {
        cin >> l[i];
    }
    int res = IINF;
    REP(i, 1<<(2*N)) {
        vector<int> v(4, 0);
        int mp = 0;
        REP(j, N) {
            int x = (i>>(2*j))&0b11;
            if(0 < v[x] && x < 3) {
                mp += 10;
            }
            v[x] += l[j];
        }
        if(v[0]*v[1]*v[2] == 0) {
            continue;
        }
        REP(j, 3) {
            mp += abs(T[j] - v[j]);
        }
        res = min(res, mp);
    }
    cout << res << endl;
    return 0;
}
