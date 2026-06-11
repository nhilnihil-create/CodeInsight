#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i;
    cin >> n >> i;
    cout << n - i + 1 << '\n';
    return 0;
}