#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string A, B, C;
    cin >> N >> A >> B >> C;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        set<char> st{A[i], B[i], C[i]};
        ans += (int) st.size() - 1;
    }

    cout << ans << endl;
    return 0;
}
