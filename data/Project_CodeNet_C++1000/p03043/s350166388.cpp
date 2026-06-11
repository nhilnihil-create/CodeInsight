#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;

int main() {
    ll N, K;
    cin >> N >> K;
    double ans = 0;
    for (int i = 1; i <= N; i++) {
        int res = i;
        double p = 1.0 / N;
        while (res < K) {
            res *= 2;
            p *= 0.5;
        }
        ans += p;
    }
    printf("%.12f\n", ans);
}