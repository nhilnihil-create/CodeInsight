#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair< int, int >;

int main() {
    int N;
    cin >> N;
    vector< P > A(N);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        A[i] = P(a, b);
    }
    vector< P > B(N);
    rep(i, N) {
        int c, d;
        cin >> c >> d;
        B[i] = P(c, d);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    set< int > used;
    rep(i, N) {
        int best = -1;
        int idx = -1;
        rep(j, N) {
            if (B[i].first > A[j].first && B[i].second > A[j].second) {
                if (best < A[j].second && !used.count(j)) {
                    best = A[j].second;
                    idx = j;
                }
            }
        }
        if (idx != -1) {
            used.insert(idx);
        }
    }
    cout << used.size() << endl;
}