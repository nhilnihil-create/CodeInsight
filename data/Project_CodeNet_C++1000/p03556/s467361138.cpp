#include<bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int l = 0, r = 40000;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (m * m <= N) l = m; else r = m;
    }
    cout << (l * l) << endl;
    return 0;
}