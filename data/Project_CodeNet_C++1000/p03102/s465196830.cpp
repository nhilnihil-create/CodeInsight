#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N,M,C;
    cin >> N >> M >> C;
    vector<int> B(M);
    rep(i,M) {
        cin >> B[i];
    }
    vector<vector<int>> A(N,vector<int>(M));
    rep(j,N) {
        rep(k,M) {
            cin >> A[j][k];
        }
    }
    int ans = 0;
    rep(l,N) {
        int sum = C;
        rep(m,M) {
            sum += B[m]*A[l][m];
        }
        if (sum > 0) {
            ans++;
        }
    }
    cout << ans << endl;
}
