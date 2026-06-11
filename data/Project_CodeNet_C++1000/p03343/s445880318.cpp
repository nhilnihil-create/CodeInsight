#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K, Q; cin >> N >> K >> Q;
    vector<int> A(N); for (auto& a : A) cin >> a;
    auto B = A;
    sort(begin(B), end(B));
    int ans = INT_MAX;
    for (int Y : B) {
        vector<int> T;
        auto candidate = [&](int i, int j) {
            int t = (j - i) - (K - 1);
            if (t <= 0) return;
            vector<int> U(begin(A)+i, begin(A)+j);
            nth_element(begin(U), begin(U)+t-1, end(U));
            copy_n(begin(U), t, back_inserter(T));
        };
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] >= Y) {
                cnt++;
            } else {
                candidate(i-cnt, i);
                cnt = 0;
            }
        }
        candidate(N-cnt, N);
        if (T.size() >= Q) {
            nth_element(begin(T), begin(T)+Q-1, end(T));
            int X = *(begin(T)+Q-1);
            ans = min(ans, X - Y);
        } else {
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}