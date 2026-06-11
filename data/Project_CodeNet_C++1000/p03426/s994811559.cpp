#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int H,W,D;
    cin >> H >> W >> D;
    vector<vector<int>>A(H,vector<int>(W));
    map<int,P>Mp;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
            Mp[A[i][j]] = make_pair(i,j);
        }
    }
    vector<int>sum(H*W+1);
    for(int i = 1; i <= H*W; i++) {
        if(i+D <= H*W) {
            sum[i+D] = sum[i]+abs(Mp[i].first-Mp[i+D].first)+abs(Mp[i].second-Mp[i+D].second);
        }
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int L,R;
        cin >> L >> R;
        cout << sum[R]-sum[L] << endl;
    }
}
