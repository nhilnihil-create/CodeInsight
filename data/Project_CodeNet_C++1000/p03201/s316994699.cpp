#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    map<ll, ll> cnt;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (cnt[A[i]] == 0)
            continue;
        cnt[A[i]]--;
        ll nxt = 1;
        while (nxt <= A[i]) {
            nxt *= 2;
        }

        if (cnt[nxt - A[i]] > 0) {
            ans++;
            cnt[nxt - A[i]]--;
        }
    }
    cout << ans << endl;
}
