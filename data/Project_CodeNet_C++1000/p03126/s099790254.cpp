#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N,M;
    int ans = 0;
    cin >> N >> M;
    vector<int> V(M,0);
    rep(i,N) {
        int K;
        cin >> K;
        rep(j,K) {
            int A;
            cin >> A;
            V[A - 1]++;
        }
    }
    rep(k,M) {
        if (V[k] == N) {
            ans++;
        }
    }
    cout << ans << endl;
}
