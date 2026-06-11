#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> L(M, 0);
    for (int i = 0; i < M; i++) {
        int k, s;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> s;
            L[i] |= (1 << (s-1));
        }
    }
    vector<int> p(M);
    for (int i = 0; i < M; i++) {
        cin >> p[i];
    }
    
    int ans;
    ans = 0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        int cnt;
        cnt = 0;
        for (int i = 0; i < M; i++) {
            if(__builtin_popcount(bit & L[i])%2 == p[i]){
                cnt++;
            }
        }
        if(cnt == M) {
            ans ++;
        }
    }
    
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
