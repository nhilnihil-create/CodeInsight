#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        y[i] = x[i];
    }
    sort(y.begin(), y.end());
    int midl = y[n / 2 - 1], midr = y[n / 2];
    for (int i = 0; i < n; i++) {
        if (x[i] <= midl)
            cout << midr << endl;
        else
            cout << midl << endl;
    }
    return 0;
}