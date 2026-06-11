#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    if (n == k) {
        cout << 1 << endl;
    } else {
        cout << (n - k - 1) / (k - 1) + 2 << endl;
    }
    return 0;
}