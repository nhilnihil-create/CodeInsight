#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    vector<pll> sum(N);
    vector<ll> taka, aoki;
    rep(i, N) {
        cin >> A[i] >> B[i];
        sum[i] = {A[i] + B[i], i};
    }

    sort(all(sum), [](pll a, pll b) { return a.first > b.first; });
    rep(i, N) {
        if (i % 2 == 0) {
            taka.push_back(sum[i].second);
        } else
            aoki.push_back(sum[i].second);
    }

    ll t = 0, a = 0;
    rep(i, taka.size()) { t += A[taka[i]]; }

    rep(i, aoki.size()) { a += B[aoki[i]]; }

    cout << t - a << endl;
}