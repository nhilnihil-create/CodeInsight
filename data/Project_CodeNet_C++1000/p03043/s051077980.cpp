#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

ll dist(ll a, ll b, ll c, ll d) {
    return abs(a-c) + abs(b-d);
}

int main() {
    int N, K;
    long double ans = 0;
    int j;

    cin >> N >> K;

    rep(i, N) {
        j = 0;
        while((i+1)*pow(2, j) < K) {
            j++;
        }
        ans += 1/(N*pow(2, j));
    }

    cout <<  fixed << setprecision(12) << ans <<endl;
}
