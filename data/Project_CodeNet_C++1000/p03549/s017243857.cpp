#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int time = m * 1900 + (n - m) * 100;
    cout << 1LL * time * (1 << m) << endl;
}
