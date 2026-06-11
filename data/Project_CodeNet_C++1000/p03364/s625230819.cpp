#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    REP(i, N) cin >> S[i];

    int result = 0;
    REP(A, N) {
        function<char(int, int)> T = [&](int i, int j) {
            return S[(i + A) % N][j];
        };
        bool is_symmetric = true;
        REP(i, N) FOR(j, i + 1, N) {
            if (T(i, j) != T(j, i)) {
                is_symmetric = false;
                break;
            }
        }
        if (is_symmetric) ++result;
    }
    result *= N;
    cout << result << endl;

    return 0;
}