#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    int g = as[0];
    for (int i = 1; i < n; i++) {
        g = __gcd(g, as[i]);
    }
    cout << g << endl;
}
