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

void solve(long long Q, std::vector<long long> A, std::vector<long long> B) {
    rep(i, Q) {
        ll a = A[i], b = B[i];
        if (a == b) {
            cout << 2 * a - 2 << endl;
            continue;
        }
        auto check = [&](ll d) {
            ll m;
            m = (d + 1) / 2 * ((d + 1) - (d + 1) / 2);
            if (m < a * b)
                return true;
            else
                return false;
        };

        // 二分探索
        ll left = 0, right = 2001000001;
        while (right - left > 1) {
            ll mid = (left + right) >> 1LL;
            if (check(mid))
                left = mid;
            else
                right = mid;
        }
        cout << left - 1 << endl;
    }
}

int main() {
    long long Q;
    scanf("%lld", &Q);
    std::vector<long long> A(Q);
    std::vector<long long> B(Q);
    for (int i = 0; i < Q; i++) {
        scanf("%lld", &A[i]);
        scanf("%lld", &B[i]);
    }
    solve(Q, std::move(A), std::move(B));
    return 0;
}
