#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>>xyz(N,vector<int>(3));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> xyz[i][j];
        }
    }
    int ans = 0;
    for(int bit = 0; bit < (1 << 3); bit++) {
        vector<int>cnt;
        for(int i = 0; i < N; i++) {
            int res = 0;
            for(int j = 0; j < 3; j++) {
                if(1 & (bit >> j)) {
                    res+=xyz[i][j];
                }
                else {
                    res+=-xyz[i][j];
                }
            }
            cnt.push_back(res);
        }
        sort(cnt.rbegin(),cnt.rend());
        int sum = 0;
        for(int i = 0; i < M; i++) {
            sum+=cnt[i];
        }
        ans = max(ans,sum);
    }
    cout << ans << endl;
}
