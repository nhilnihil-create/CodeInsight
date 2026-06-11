#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    vector<pair<ll, ll>> C(N);
    rep(i, N) {
        cin >> A[i] >> B[i];
        C[i] = make_pair(- A[i] - B[i], A[i]);
    }
    sort(C.begin(), C.end());
    ll Ta = 0, Ao = 0;
    rep(i, N) {
        if (i & 1) Ao += - C[i].first - C[i].second;
        else Ta += C[i].second;
    }
    cout << Ta - Ao << "\n";
}