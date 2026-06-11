#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    vector<int> k(Q);
    rep(i, Q) cin >> k[i];
    vector<ll> D(N + 1, 0), M(N + 1, 0);
    rep(i, N) {
        D[i + 1] = D[i] + (S[i] == 'D');
        M[i + 1] = M[i] + (S[i] == 'M');
    }
    rep(i, Q) {
        ll ans = 0, DM = 0;
        rep(j, N) {
            if (j >= k[i] && S[j - k[i]] == 'D') DM -= M[j] - M[j - k[i] + 1];
            if (S[j] == 'M') {
                DM += D[j] - D[max(0, j - k[i] + 1)];
            }
            if (S[j] == 'C') ans += DM;
            //cout << j << " " << DM << endl;
        }
        cout << ans << endl;
    }
    //rep(i, N + 1) cout << i << " " << D[i] << " " << M[i] << endl;
}