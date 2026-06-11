#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)
#define int long long

const int maxn = 5e5 + 1, mod = 1e9 + 7;

using namespace std;

int a[maxn], b[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    stack<int> st;
    for (; n >= 1; n--) {
        int ci = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (b[i] == i + 1) {
                ci = i;
                break;
            }
        }
        if (ci == -1) {
            cout << -1;
            return 0;
        }
        st.push(ci + 1);
        for (int i = ci + 1; i < n; i++)
            swap(b[i], b[i - 1]);
    }
    while (!st.empty()) {
        cout << st.top() << '\n';
        st.pop();
    }
    return 0;
}
