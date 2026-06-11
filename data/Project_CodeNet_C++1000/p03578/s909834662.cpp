#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const string YES = "YES";
const string NO = "NO";

void solve(long long N, std::vector<long long> D, long long M, std::vector<long long> T) {
    map<ll, ll> problemcnt;
    rep(i, N) { problemcnt[D[i]]++; }
    rep(i, M) {
        problemcnt[T[i]]--;
        if (problemcnt[T[i]] < 0) {
            cout << NO << endl;
            return;
        }
    }
    cout << YES << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> D(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &D[i]);
    }
    long long M;
    scanf("%lld", &M);
    std::vector<long long> T(M);
    for (int i = 0; i < M; i++) {
        scanf("%lld", &T[i]);
    }
    solve(N, std::move(D), M, std::move(T));
    return 0;
}
