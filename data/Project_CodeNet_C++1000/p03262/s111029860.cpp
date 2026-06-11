#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, X;

int gcd(int a, int b) {
    while (b) {
        int t = a;
        a = b;
        b = t%b;
    }
    return a;
}

signed main() {
    cin >> N >> X;
    int G = 0;
    rep(i, N) {
        int x; cin >> x;
        G = gcd(G, abs(X-x));
    }
    cout << G << endl;
}