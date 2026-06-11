#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    vector<pair<ll, int>> S(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        S[i].first = A[i] + B[i];
        S[i].second = i;
    }

    sort(S.begin(), S.end(), greater<pair<ll, int>>());

    bool takahashi = true;
    ll res = 0;
    for(auto s: S) {
        if(takahashi) {
            res += A[s.second];
        } else {
            res -= B[s.second];
        }
        takahashi = !takahashi;
    }
    cout << res << endl;
}