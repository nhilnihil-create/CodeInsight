#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> v(M);
    for (int i = 0; i < M; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    if (N >= M) {
        cout << 0 << endl;
    }
    else {
        vector<ll> A;
        for (int i = 0; i < M - 1; i++) {
            A.push_back(v[i + 1] - v[i]);
        }
        ll sum = 0;
        sort(A.begin(), A.end());
        for (int i = 0; i < M - N; i++) {
            sum += A[i];
        }
        cout << sum << endl;
    }
}