#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;

int N;
const int MAX_N = 2.0e5 + 10;
ll A[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    bool possible = true;
    
    if (A[0] != 0) possible = false;
    for (int i = 1; i < N; i++) {
        if (A[i-1] < A[i] && A[i-1] + 1 != A[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        ll ans = 0;
        for (int i = N-1; i >= 1; i--) {
            if (A[i-1] + 1 == A[i]) {
                ans++;
            }
            else {
                ans += A[i];
            }
        }
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }
    
    return 0;
}