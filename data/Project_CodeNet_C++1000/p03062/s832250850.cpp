#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    int cnt = 0;
    rep(i,N) {
        int a; cin >> a;
        if (a <= 0) a = -a, cnt++;
        A[i] = a;
    }
    sort(A.begin(), A.end());
    ll res = 0;
    if (cnt > 0 && cnt % 2 == 1) A[0] = -A[0];
    rep(i,N) res += A[i];
    cout << res << endl;
}
