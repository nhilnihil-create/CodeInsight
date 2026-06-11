#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long R) {
    if (R < 1200) {
        cout << "ABC" << endl;
    } else if (R < 2800) {
        cout << "ARC" << endl;
    } else {
        cout << "AGC" << endl;
    }
}

int main() {
    long long R;
    scanf("%lld", &R);
    solve(R);
    return 0;
}
