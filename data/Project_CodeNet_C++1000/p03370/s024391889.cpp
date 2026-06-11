#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X; cin >> N >> X;
    int m = 1000;
    for (int i=0; i<N; i++) {
        int tmp; cin >> tmp;
        X -= tmp;
        m = min(tmp, m);
    }
    cout << N + X / m << endl;
}