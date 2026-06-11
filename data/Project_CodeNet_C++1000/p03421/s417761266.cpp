#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    if (A + B - 1 > N || A * B < N) {
        cout << -1 << endl;
        return 0;
    }
    if (A == 1) {
        rep(i, B) {
            cout << N - i << " ";
        }
        cout << endl;
        return 0;
    }
    int Q = (N - B) / (A - 1), R = (N - B) % (A - 1);
    //cout << "Q=" << Q << ", R=" << R << endl;
    rep(i, Q) {
        rep(j, A) {
            cout << N - A - i * A + j + 1 << " ";
        }
    }
    if (R == 0) {
        rep(i, B - Q) {
            cout << B - Q - i << " ";
        }
        cout << endl;
        return 0;
    }
    rep(i, R + 1) {
        cout << N - Q * A - R + i << " ";
    }
    rep(i, B - Q - 1) {
        cout << B - Q - 1 - i << " ";
    }
    cout << endl;
}