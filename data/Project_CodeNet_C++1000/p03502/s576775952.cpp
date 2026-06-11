#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, f = 0, X;
    cin >> N;
    X = N;
    while (X > 0) {
        f += X % 10;
        X /= 10;
    }
    if (N % f) cout << "No\n";
    else cout << "Yes\n";
}