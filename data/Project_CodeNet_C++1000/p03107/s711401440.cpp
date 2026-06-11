#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    stack<int> st;
    int ans = 0;
    for (char c : S) {
        if (!st.empty() && st.top() != c) {
            st.pop();
            ans += 2;
        } else {
            st.push(c);
        }
    }
    cout << ans << endl;
}