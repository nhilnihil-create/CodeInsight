#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> P1;
typedef pair<P, P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i, x) for (long long i = 0; i < x; i++)
#define repn(i, x) for (long long i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(), x.end())
#define ERASE(x) x.erase(unique(x.begin(), x.end()), x.end())
#define POSL(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define POSU(x, v) (upper_bound(x.begin(), x.end(), v) - x.begin())
vector<pair<string, P>> vec;
// vector<vector<int>> data(3, vector<int>(4));

void solve(long long N, long long M, long long Q, std::vector<long long> L, std::vector<long long> R,
           std::vector<long long> p, std::vector<long long> q) {
    vector<vector<ll>> data(N + 1, vector<ll>(N + 1));
    rep(i, M) data[L[i]][R[i]]++;
    vector<vector<ll>> sum(N + 1, vector<ll>(N + 1));
    rep(i, N) {
        rep(j, N) { sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + data[i + 1][j + 1]; }
    }
    rep(i, Q) { cout << sum[q[i]][q[i]] - sum[p[i] - 1][q[i]] - sum[q[i]][p[i] - 1] + sum[p[i] - 1][p[i] - 1] << endl; }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long M;
    scanf("%lld", &M);
    long long Q;
    scanf("%lld", &Q);
    std::vector<long long> L(M);
    std::vector<long long> R(M);
    for (int i = 0; i < M; i++) {
        scanf("%lld", &L[i]);
        scanf("%lld", &R[i]);
    }
    std::vector<long long> p(Q);
    std::vector<long long> q(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%lld", &p[i]);
        scanf("%lld", &q[i]);
    }
    solve(N, M, Q, std::move(L), std::move(R), std::move(p), std::move(q));
    return 0;
}
