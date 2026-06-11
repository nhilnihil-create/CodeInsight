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

void solve(long long K, std::vector<long long> A) {
    auto check1 = [&](ll d) {
        bool flg = false;
        ll n = d;
        rep(i, K) {
            if (n >= A[i])
                n -= n % A[i];
            else
                return false;
        }
        if (n >= 2)
            return true;
        else
            return false;
    };

    auto check2 = [&](ll d) {
        bool flg = false;
        ll n = d;
        rep(i, K) {
            if (n >= A[i])
                n -= n % A[i];
            else
                return false;
        }
        if (n >= 3)
            return true;
        else
            return false;
    };

    // 二分探索
    ll left = -1, right = (ll)2e18;
    while (right - left > 1) {
        ll mid = (left + right) >> 1;
        if (check1(mid))
            right = mid;
        else
            left = mid;
    }

    ll n = right;
    rep(i, K) { n -= n % A[i]; }

    if (n != 2) {
        cout << "-1" << endl;
    } else {
        cout << right << " ";

        left = -1, right = (ll)2e18;
        while (right - left > 1) {
            ll mid = (left + right) >> 1;
            if (check2(mid))
                right = mid;
            else
                left = mid;
        }
        cout << left << endl;
    }
}

int main() {
    long long K;
    scanf("%lld", &K);
    std::vector<long long> A(K);
    for (int i = 0; i < K; i++) {
        scanf("%lld", &A[i]);
    }
    solve(K, std::move(A));
    return 0;
}
