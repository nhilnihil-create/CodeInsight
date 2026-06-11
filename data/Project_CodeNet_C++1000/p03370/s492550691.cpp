#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int m[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> m[i];
        sum += m[i];
    }

    sort(m, m+n);
    cout << n + (x-sum)/m[0] << endl;
}