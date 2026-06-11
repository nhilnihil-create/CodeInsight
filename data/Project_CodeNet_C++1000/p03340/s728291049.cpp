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
    cin >> N;
    vector<int> v(N);
    REP(i, N) {
        cin >> v[i];
    }
    /*
    int N = 4;
    vector<int> v = {2, 5, 4, 6};
    */

    LL l = 0;
    LL r = 0;
    LL c = 0;
    LL s = 0;
    LL res = 0;

    for(;r < N;r++) {
        c ^= v[r];
        s += v[r];
        for(;c != s;l++) {
            c ^= v[l];
            s -= v[l];
        }
        res += r - l + 1;
    }
    cout << res << endl;
    return 0;
}
