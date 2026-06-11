#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> L(N), R(N);
    for(int i=0; i<N; ++i) cin >> L[i] >> R[i];

    sort(L.begin(), L.end(), greater<long long>());
    sort(R.begin(), R.end());

    vector<long long> Lsum(N+1, 0);
    vector<long long> Rsum(N+1, 0);
    for(int i=0; i<N; ++i) {
        Lsum[i + 1] = Lsum[i] + L[i];
        Rsum[i + 1] = Rsum[i] - R[i];
    }

    long long res = 0;
    for(int r=0; r<=N; ++r) {
        for(int l=r-1; l<=r+1; ++l) {
            if(l < 0 || l + r > N) continue;
            long long tmp = Lsum[r] + Rsum[l];
            res = max(res, 2LL * tmp);
        }
    }

    cout << res << endl;
}