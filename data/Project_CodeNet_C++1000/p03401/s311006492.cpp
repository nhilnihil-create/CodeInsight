#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define MOD (int)1e9+7;

using ll = long long;
using namespace std;

int main() {
    int N;
    ll ans = 0;
    cin >> N;
    vector<int> A(N+1);
    A[0] = 0;
    rep1(i, N) 
        cin >> A[i];
    A.push_back(0);

    rep1(i, N+1) {
        ans += abs(A[i] - A[i-1]);
    }
    
    rep1(i, N) {
        int pdif = A[i] - A[i-1];
        int ldif = A[i] - A[i+1];
        if(pdif*ldif <= 0) {
            cout << ans << "\n";
        } else {
            cout << ans - 2*min(abs(pdif), abs(ldif)) << "\n";
        }
    }

    
    return 0;
}
