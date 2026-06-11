// 7/3
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int d = A[0];
    for (int i = 1; i < N; i++) {
        d = gcd(d, A[i]);
    }

    cout << d << endl;
    return 0;
}