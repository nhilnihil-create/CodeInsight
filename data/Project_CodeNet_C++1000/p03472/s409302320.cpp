#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N, H;
vector<int> A, B;


void input() {
    cin >> N >> H;
    A = B = vector<int>(N);
    rep(i, N) cin >> A[i] >> B[i];
}


int main() {
    input();
    sort(B.rbegin(), B.rend());
    int m = *max_element(A.begin(), A.end());
    int ans = 0;
    rep(i, N) {
        if (H > 0 && B[i] > m) {
            H -= B[i];
            ans++;
        }
    }
    if (H > 0) ans += (H - 1) / m + 1;
    cout << ans << endl;
}
