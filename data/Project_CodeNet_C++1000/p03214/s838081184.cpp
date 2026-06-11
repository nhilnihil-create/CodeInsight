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
    IN(N);
    V a(N);
    float sum = 0;
    REP(i, N) {
        IN(a[i]);
        sum += a[i];
    }
    sum /= N;
    int min = 0, n = 0;
    REP(i, N) {
        if(abs(sum - n) > abs(sum - a[i])) {
            min = i;
            n = a[i];
        }
    }
    OUT(min);
}