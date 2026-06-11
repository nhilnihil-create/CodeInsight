#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    rep(i, N) {
        if (A[i] > i) {
            cout << -1 << endl;
            return 0;
        }

        if (i < N - 1 && A[i] + 1 < A[i + 1]) {
            cout << -1 << endl;
            return 0;
        }
    }

    ll ans = 0;
    for (int i = 1; i < N; ++i) {
        if (A[i - 1] + 1 != A[i]) {
            ans += A[i - 1];
        }
    }

    ans += A[N - 1];
    
    cout << ans << endl;
}