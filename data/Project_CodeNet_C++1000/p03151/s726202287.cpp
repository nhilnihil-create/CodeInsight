#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int>A(N);
    vector<int>B(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    priority_queue<int>que;
    int ans = 0;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] < B[i]) {
            ans++;
            sum += B[i] - A[i];
        } else {
            que.push(A[i]-B[i]);
        }
    }
    if (sum == 0) {
        cout << 0 << endl;
        return 0;
    }

    while (!que.empty()) {
        int x = que.top();
        que.pop();
        sum -= x;
        ans++;
        if (sum <= 0) {
            break;
        }
    }
    if (sum > 0) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
