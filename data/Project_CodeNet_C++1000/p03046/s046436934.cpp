//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


inline void print() {
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest) {
    cout << first << ' ';
    print(rest...);
}


void solve() {
    int M, K; cin >> M >> K;

    if (K >= 1<<M) {
        cout << -1 << endl;
        return;
    }

    if (M == 1) {
        if (K == 0) {
            print(0, 0, 1, 1);
        }
        else {
            cout << -1 << endl;
        }
        return;
    }

    for (int i = 0; i < 1<<M; i++) {
        if (i == K) continue;
        cout << i << endl;
    }
    cout << K << endl;
    for (int i = (1<<M)-1; i>= 0; i--) {
        if (i == K) continue;
        cout << i << endl;
    }
    cout << K << endl;
}


int main() {
    solve();
    return 0;
}