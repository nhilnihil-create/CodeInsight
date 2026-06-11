#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

ll solve() {
    ll N;
    cin >> N;
    ll NN = 1LL << N;
    vector<ll> A(NN);
    for ( int i = 0; i < NN; i++ ) {
        cin >> A[i];
    }
    vector<pii> tmp(5);
    vector<int> ix1(NN, -1), ix2(NN, -1); // ix1[k] (k|i)==kとなるiでA[i]が最大となるi
    ix1[0] = 0;
    for ( int k = 0; k < NN; k++ ) {
        for ( int i = 0; i < N; i++ ) {
            int h = k | (1 << i);
            if ( h == k ) continue;
            priority_queue<pii> q;
            q.push(pii(A[h],h));
            q.push(pii(ix1[h] >= 0 ? A[ix1[h]] : -1, ix1[h]));
            q.push(pii(ix1[k] >= 0 ? A[ix1[k]] : -1, ix1[k]));
            q.push(pii(ix2[h] >= 0 ? A[ix2[h]] : -1, ix2[h]));
            q.push(pii(ix2[k] >= 0 ? A[ix2[k]] : -1, ix2[k]));
            ix1[h] = q.top().second;
            while( q.top().second != -1 && ix1[h] == q.top().second ) q.pop();
            ix2[h] = q.top().second;
        }
    }

    ll m = 0;
    vector<ll> ans(NN);
    for ( int i = 1; i < NN; i++ ) {
        m = max(m, A[ix1[i]] + A[ix2[i]]);
        ans[i] = m;
    }

    for ( int i = 1; i < NN; i++ ) {
        cout << ans[i] << "\n";
    }
    return 0;
}

int main() {
    solve();
    return 0;
}