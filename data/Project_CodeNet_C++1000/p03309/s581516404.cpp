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
    vector<LL> A(N);
    REP(i, N) {
        cin >> A[i];
        A[i] -= i;
    }
    sort(ALL(A));
    LL b = A[N/2];
    LL res = 0;
    REP(i, N) {
        res += abs(A[i] - b);
    }
    cout << res << endl;
    return 0;
}
