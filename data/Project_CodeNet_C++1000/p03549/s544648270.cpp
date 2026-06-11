#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    // Atcoder
    // template: cpp
    ll n, m;
    cin >> n >> m;

    cout << pow(2, m) * (1900 * m + 100 * (n - m));
}
