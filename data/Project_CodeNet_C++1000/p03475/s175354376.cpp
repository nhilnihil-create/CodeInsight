#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
int C[510], S[510], F[510];

signed main() {
    cin >> N;
    rep(i, N-1) cin >> C[i] >> S[i] >> F[i];
    rep(i, N) {
        int now = 0;
        for (int j=i; j<N-1; j++) {
            now = max(S[j], (now+F[j]-1)/F[j]*F[j]);
            now += C[j];
        }
        cout << now << endl;
    }
}