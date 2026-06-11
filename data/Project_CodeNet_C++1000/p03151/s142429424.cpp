#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int cnt = 0;
    long long sumM = 0;
    for (int i = 0; i < N; i++) {
        int B;
        cin >> B;
        A[i] -= B;
        if (A[i] < 0) {
            sumM += -A[i];
            cnt++;
        }
    }

    if (cnt == 0) {
        cout << 0 << endl;
        return 0;
    }

    sort(A.begin(), A.end(), greater<int>());

    long long sumP = 0;
    int ans = cnt;
    for (int i = 0; i < N - cnt; i++) {
        sumP += A[i];
        ans++;
        if (sumP >= sumM) break;
    }

    if (sumP >= sumM) cout << ans << endl;
    else cout << -1 << endl;
}