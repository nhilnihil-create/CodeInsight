#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    int N, result = 0, tmp;
    cin >> N;
    vector<vector<int> > A(2, vector<int>(N));
    REP(i, N) {
        cin >> A[0][i];
    }
    REP(i, N) {
        cin >> A[1][i];
    }
    REP(i, N) {
        tmp = 0;
        REP(j, i+1) {
            tmp += A[0][j];
        }
        FOR(j, i, N) {
            tmp += A[1][j];
        }
        if (tmp > result) {
            result = tmp;
        }
    }
    cout << result << endl;
    return 0;
}
