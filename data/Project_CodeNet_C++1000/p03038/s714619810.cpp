#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int N, M;

void solve() {
    cin >> N >> M;
    ll A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A + N);
    priority_queue<P> O;
    for (int i = 0; i < M; ++i) {
        int b, c;
        cin >> b >> c;
        O.push(P(c, b));
    }
    int i = 0;
    while(!O.empty()) {
        P t = O.top(); O.pop();
        int count = 0;
        while(A[i] < t.first && count < t.second) {
            A[i] = t.first;
            count++;
            i++;
        }
        if (count == 0) break;
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += A[i];
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
