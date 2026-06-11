#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, H, W;
int A[1100], B[1100];

int main() {
    cin >> N >> H >> W;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (H <= A[i] && W <= B[i]) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
