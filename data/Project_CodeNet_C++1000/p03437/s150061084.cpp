#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >> n >> m;
    cout << (n*(m-1) %m==0 ? -1 : (n*(m-1))) << endl;
}