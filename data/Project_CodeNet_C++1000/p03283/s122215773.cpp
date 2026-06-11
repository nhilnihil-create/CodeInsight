#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M,Q;
    cin >> N >> M >> Q;
    vector<vector<int>>cnt(N+2,vector<int>(N+2));
    for(int i = 0; i < M; i++) {
        int L,R;
        cin >> L >> R;
        cnt[L][R]++;
    }
    for(int i = N; i >= 1; i--) {
        for(int j = 1; j <= N; j++) {
           cnt[i][j] = cnt[i][j]+cnt[i+1][j]+cnt[i][j-1]-cnt[i+1][j-1];
        }
    }
    for(int i = 0; i < Q; i++) {
        int p,q;
        cin >> p >> q;
        cout << cnt[p][q] << endl;
    }
}