#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    rep(i,0,N) cin >> A[i];
    rep(i,0,N) cin >> B[i];
    rep(i,0,N) cin >> C[i];

    sort(all(A));
    sort(all(B));
    sort(all(C));
    vector<int> numAs_vs_B(N);
    vector<int> numBs_vs_C(N);
    rep(i,0,N) {
        numAs_vs_B[i] = lower_bound(all(A),B[i]) - A.begin();
        numBs_vs_C[i] = lower_bound(all(B),C[i]) - B.begin();
    }
    vector<ll> sum_nAvB(N);
    ll tmp = 0;
    rep(i,0,N) {
        tmp += numAs_vs_B[i];
        sum_nAvB[i] = tmp;
    }
    ll ans = 0;
    rep(i,0,N) {
        ans += numBs_vs_C[i] > 0 ? sum_nAvB[numBs_vs_C[i]-1] : 0;
    }

    cout << ans << endl;
}