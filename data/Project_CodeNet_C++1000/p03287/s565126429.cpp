#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    rep(i, n) {
        cin >> A[i];
    }

    vector<int> B(n + 1);
    for (int i = 0; i < n; i++) {
        B[i + 1] += (B[i] + A[i]);
        B[i + 1] %= m;
    }

    map<int, int> M;
    ll cnt = 0;
    for (int i = 0; i < n + 1; i++) {
        cnt += M[B[i]];
        M[B[i]]++;
    }

    cout << cnt << endl;
}