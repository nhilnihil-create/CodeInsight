#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
 
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    if (A[0] != 0) {
        cout << "-1\n";
        return 0;
    }
    ll ans = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        if (A[i] == A[i + 1] - 1) continue;
        if (A[i] < A[i + 1] - 1) {
            cout << "-1\n";
            return 0;
        }
        ans += A[i];
    }
    cout << ans << endl;
}