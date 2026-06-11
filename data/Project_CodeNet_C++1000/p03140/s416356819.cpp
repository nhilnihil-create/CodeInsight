#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i != n; ++i)
#define REPR(i, n) for(int i = n - 1; i != -1; --i)
#define FOR(i, a, b) for(int i = a; i != b; ++i)
#define RBF(i, n) for(auto &i : n)
#define ABS(n) (n < 0 ? -n : n)
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define IN(n) (cin >> n)
#define OUT(n) (cout << n << "\n")
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define V vector<int>

using namespace std;
using ll = long long;

int main() {
    int N;
    string A, B, C;
    cin >> N >> A >> B >> C;
    int count = 0;
    REP(i, N) {
        if(A[i] == B[i]) {
            if(A[i] != C[i]) {
                count++;
            }
        }
        else if(A[i] == C[i]) {
            if(A[i] != B[i]) {
                count++;
            }
        }
        else if(B[i] == C[i]) {
            if(A[i] != B[i]) {
                count++;
            }
        }
        else {
            count += 2;
        }
    }
    OUT(count);
}