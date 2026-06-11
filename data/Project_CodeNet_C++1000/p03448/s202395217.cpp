#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int res = 0;
    REP(i, A+1) {
        REP(j, B+1) {
            REP(k, C+1) {
                int total = 500*i + 100*j + 50*k;
                if (total == X) ++res;
            }
        }
    }
    cout << res << endl;
}
