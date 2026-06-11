#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ll = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    size_t n;
    cin >> n;

    vector<ll> Lucas(n + 1);
    Lucas.at(0) = 2;
    Lucas.at(1) = 1;
    for (size_t i = 2; i <= n; i++) {
        Lucas.at(i) = Lucas.at(i - 1) + Lucas.at(i - 2);
        // cout << Lucas.at(i) << endl;
    }
    cout << Lucas.at(n) << endl;
}