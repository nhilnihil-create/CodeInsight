#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto &i : x) cin >> i;
    vector<int> copy = x;
    sort(copy.begin(), copy.end());
    int m1 = copy[n/2-1], m2 = copy[n/2];
    for (int i = 0; i < n; i++) {
        if (x[i] <= m1) cout << m2 << endl;
        else cout << m1 << endl;
    }
    return 0;
}