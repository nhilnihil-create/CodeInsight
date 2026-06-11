#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

long long GCD(long long x, long long y) {
    if (x % y == 0) return y;
    return GCD(y, x % y);
}

long long LCM(long long x, long long y) {
    return x / GCD(x, y) * y;
}

int main() {
    long long N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    
    long long K = LCM(N, M);
    map<long long, char> ans;
    bool judge = true;
    for (long long i = 0; i < N; ++i) {
        ans[K / N * i] = S[i];
    }
    for (long long i = 0; i < M; ++i) {
        if (ans.count(K / M * i)) {
            if (ans[K / M * i] != T[i]) judge = false;
        }
    }
    if (judge) cout << K << endl;
    else cout << -1 << endl;
    return 0;
}
