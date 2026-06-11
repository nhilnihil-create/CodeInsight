#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;


int main() {
    int N, x;
    cin >> N >> x;

    int A[N];
    rep(i, N) cin >> A[i];
    sort(A, A+N);

    int ans = N-1;
    rep(i, N) {
        x -= A[i];
        if (x < 0) {
            ans = i;
            break;
        } else if (x == 0) {
            ans = i + 1;
            break;
        } 
    }

    cout << ans << endl;

    return 0;
}