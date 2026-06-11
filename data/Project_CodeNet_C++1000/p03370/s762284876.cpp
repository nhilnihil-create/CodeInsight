#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    int m;
    int m_min = 1100;
    cin >> N >> X;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> m;
        m_min = min(m, m_min);
        X -= m;
        ans++;
    }

    ans += X / m_min;

    cout << ans << endl;
}