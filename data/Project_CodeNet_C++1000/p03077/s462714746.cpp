#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long minv = (1LL<<60);
    for (int i = 0; i < 6; i++) {
        long long p;
        cin >> p;
        minv = min(minv, p);
    }
    cout << (N + minv - 1) / minv + 4 << endl;
}