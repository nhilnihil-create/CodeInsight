#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
const int MAX_N = 2.0e5 + 100;
int P[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> P[i];

    int Q[N+1];
    for (int i = 0; i < N; i++) {
        Q[P[i]] = i;
    }

    int cnt = 1;
    int ans = 0;
    for (int i = 1; i <= N-1; i++) {
        if (Q[i] < Q[i+1]) {
            cnt++;
        }
        else {
            ans = max(ans, cnt);
            cnt = 1; 
        }
    }

    if (ans == 0) cout << ans << endl;
    else cout << N - ans << endl;

    return 0;
}