#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    ll ans = 0;
    vector<int> L(N), R(N);
    for(int i = 0; i < N; ++i) {
        cin >> L[i] >> R[i];
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    ll now = 0;
    for(int i = 0; i <= N / 2; i++) {
        now += 2 * L[N - i - 1];
        ans = max(ans, now);
        if(i * 2 + 1 >= N)
            break;
        now -= 2 * R[i];
        ans = max(ans, now);
    }
    now = 0;
    for(int i = 0; i <= N / 2; i++) {
        now -= 2 * R[i];
        ans = max(ans, now);
        if(i * 2 + 1 >= N) break;
        now += 2 * L[N - i - 1];
        ans = max(ans, now);
    }
    cout << ans << endl;
}