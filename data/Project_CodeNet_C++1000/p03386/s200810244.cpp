#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    set<int> st;
    for (int i = a; i < a + k && i <= b; ++i)
        st.insert(i);

    for (int i = b; i > b - k && i >= a; --i)
        st.insert(i);

    for (auto ans : st)
        cout << ans << " ";
    cout << endl;

    return 0;
}