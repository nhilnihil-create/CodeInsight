#include <bits/stdc++.h>
using namespace std;
using Int = long long;
template <class T> bool chmin(T& x, T y) {
    return x > y ? (x = y, true) : false;
}
int main() {
    string S; cin >> S;
    const int INF = 1e9;
    vector<int> A(1 << 26, INF);
    A[0] = 0;
    int hash = 0;
    for (int i = 0; i < S.size(); i++) {
        hash ^= 1 << (S[i] - 'a');
        int val = INF;
        chmin(val, A[hash] + 1);
        for (int j = 0; j < 26; j++) {
            chmin(val, A[hash ^ (1 << j)] + 1);
        }
        chmin(A[hash], val);
    }
    cout << max(1, A[hash]) << '\n';
    return 0;
}
