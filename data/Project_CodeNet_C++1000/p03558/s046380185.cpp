#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int k;
    cin >> k;

    const int INF = 9 * 5;
    vector<int> d(k, INF);
    deque<int> st;
    st.push_front(1);
    d[1] = 1;

    while (!st.empty()) {
        auto cur = st.front(); st.pop_front();
        if (cur == 0) break;

        if (d[cur] < d[(10 * cur) % k]) {
            d[(10 * cur) % k] = d[cur];
            st.push_front((10 * cur) % k);
        }
        if (d[cur] + 1 < d[(cur + 1) % k]) {
            d[(cur + 1) % k] = d[cur] + 1;
            st.push_back((cur + 1) % k);
        }
    }

    cout << d[0] << endl;

    return 0;
}
