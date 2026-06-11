#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> D(N);
    rep(i, N) cin >> D[i];
    int M;
    cin >> M;
    vector<int> T(M);
    rep(i, M) cin >> T[i];
    sort(ALL(D));
    sort(ALL(T));
    int idx = 0;
    rep(i, M) {
        bool flag = true;
        FOR(j, idx, N) if (T[i] == D[j]) {flag = false; idx = j + 1; break;}
        if (flag) {cout << "NO" << endl; return 0;}
    }
    cout << "YES" << endl;
    return 0;
}