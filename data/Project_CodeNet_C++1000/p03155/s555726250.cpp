//#pragma GCC optimize("O3", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using old = long double;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, w, h;
    cin >> n >> w >> h;
    cout << (n - w + 1) * (n - h + 1);
    return 0;
}