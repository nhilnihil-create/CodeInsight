#include <bits/stdc++.h>
using namespace std;
using ll = long long; // ll は long long　と同じとする。(int64_t)
int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<int> C(N);
    long long total = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        C[i] = A[i] - B[i];
        if (A[i] < B[i]) {
            total += B[i] - A[i];
            ans++;
        }
    }
    sort(C.rbegin(), C.rend());
    for (int i = 0; i < N; ++i) {
        if (total <= 0) {
            break;
        }
        if (C[i] <= 0) {
            cout << -1 << endl;
            return 0;
        }
        total-=C[i];
        ans++;
    }
    cout << ans << endl;
    return 0;
}