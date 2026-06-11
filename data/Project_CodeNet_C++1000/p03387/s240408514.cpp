#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    vector<int> A(3);
    int result = 0;
    cin >> A[0] >> A[1] >> A[2];
    while (true) {
        sort(ALL(A));
        if (A[0] == A[1] && A[0] == A[2]) {
            break;
        }
        if (A[1] == A[2]) {
            if ((A[1] - A[0]) % 2) {
                A[0]++;
                A[1]++;
            } else {
                A[0] += 2;
            }
        } else {
            A[0]++;
            A[1]++;
        };
        result++;
    }
    cout << result << endl;
    return 0;
}

/*
 * 2 5 4
 * 2 4 5
 *
 */