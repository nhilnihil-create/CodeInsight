// 7/3
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());

    // while (M--) {
    //     int b, c;
    //     cin >> b >> c;
    // }
    vector<P> q(M);
    rep(i, M) {
        cin >> q[i].second >> q[i].first;
    }
    sort(q.begin(), q.end(), greater<P>());

    ll res = 0;
    // int id = 0;
    // rep(i, M) {
    //     printf("C, B = %d, %d\n", q[i].first, q[i].second);
    //     while (id < q[i].second) {
    //     // for(int j = id; j < q[i].second; j++) {
    //         res += max(A[id], q[i].first);
    //         id++;
    //     }
    // }
    // // for (int i = id; i < N; i++) {
    // //     res += A[i];
    // // }
    // while (id < N) {
    //     res += A[id++];
    // }

    int id = 0;
    rep(i, M) {
        rep(j, q[i].second) {
            // while (id < N && A[id] < q[i].first) {
            //     // res += max(A[id], q[i].first);
            //     res += q[i].first;
            //     id++;
            // }
            if (id < N && A[id] < q[i].first) {
                res += q[i].first;
                id++;
            } else {
                break;
            }
        }
    }

    while (id < N) {
        res += A[id++];
    }

    cout << res << endl;
}