#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int M = -1, m = 1e9 + 10;
    for (int i=0; i<n; ++i) {
        int num; cin >> num;
        if (num > M) M = num;
        if (num < m) m = num;
    }
    cout << M - m << endl;
}