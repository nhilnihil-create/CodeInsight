#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>>s(M);
    vector<int>p(M);
    for(int i = 0; i < M; i++) {
        int k;cin >> k;
        for(int j = 0; j < k; j++) {
            int X;cin >> X;X--;
            s[i].push_back(X);
        }
    }
    for(int i = 0; i < M; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for(int bit = 0; bit < (1 << N); bit++) {
        bool ok = true;
        for(int i = 0; i < M; i++) {
            int cnt = 0;
            for(int j = 0; j < s[i].size(); j++) {
                if(1 & (bit >> s[i][j])) {
                    cnt++;
                }
            }
            if(cnt%2 != p[i]) {
                ok = false;
            }
        }
        if(ok) {
            ans++;
        }
    }
    cout << ans << endl;
}
