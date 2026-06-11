#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int K;
    cin >> K;
    vector<ll> A(K);
    rep(i, K) cin >> A[i];
    ll minN = 2, maxN = 2;
    for (int i = K - 1; i >= 0; i--) {
        minN = (minN + A[i] - 1) / A[i] * A[i];
        maxN = maxN / A[i] * A[i] + A[i] - 1;
        //cout << minN << " " << maxN << "\n";
    }
    if (minN > maxN) cout << "-1\n";
    else cout << minN << " " << maxN << "\n";
}