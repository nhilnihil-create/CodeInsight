#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define MOD 1e9+7;

using ll = long long;
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    set<int> st;
    vector<int> cnt(N, 0);
    
    rep(i, N) {
        int A;
        cin >> A;
        st.insert(A);
        cnt[A]++;
    }

    int num = (int)st.size() - K;
    int ans = 0, tmp = 0;
    if(num > 0) {
        sort(cnt.begin(), cnt.end(), greater<int>());

        for (int i = 0; i < K; i++) {
            if(cnt[i] > 0) {
                //cout << i << cnt[i] << "\n";
                tmp += cnt[i];
            }
        }
        ans = N - tmp;
    }

    cout << ans << "\n";
    return 0;
}
