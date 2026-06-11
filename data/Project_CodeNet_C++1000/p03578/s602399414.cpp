#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, D, M, T;
    cin >> N;
    map<int, int> m;
    rep(i, N) {
        cin >> D;
        m[D]++;
    }
    cin >> M;
    rep(i, M) {
        cin >> T;
        if (m[T] <= 0) {
            cout << "NO\n";
            return 0;
        }
        m[T]--;
    }
    cout << "YES\n";
}