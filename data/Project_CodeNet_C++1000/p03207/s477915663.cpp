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
vector<pair<string, P> > vec;
// vector<vector<int>> data(3, vector<int>(4));

void solve(long long N, std::vector<long long> p) {
    ll m = 0, res = 0;
    rep(i, N) {
        res += p[i];
        m = max(m, p[i]);
    }
    res -= m / 2;
    cout << res << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> p(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &p[i]);
    }
    solve(N, std::move(p));
    return 0;
}
