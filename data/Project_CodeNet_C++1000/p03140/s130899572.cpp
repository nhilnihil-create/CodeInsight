#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string A, B, C;
    cin >> N >> A >> B >> C;

    map<int, int> mp;
    mp[3] = 2;
    mp[2] = 1;
    mp[1] = 0;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        set<char> st;
        st.insert(A[i]);
        st.insert(B[i]);
        st.insert(C[i]);
        ans += mp[st.size()];
    }

    cout << ans << endl;
    return 0;
}