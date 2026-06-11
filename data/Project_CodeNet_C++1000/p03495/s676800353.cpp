#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N, K;
    cin >> N >> K;

    int A[2000020];
    rep(i, N) {
        int a;
        cin >> a;
        A[a-1]++;
    }

    sort(A, A+N);
    int ans = 0;
    rep(i, N-K) ans += A[i];

    cout << ans << endl;

    return 0;
}