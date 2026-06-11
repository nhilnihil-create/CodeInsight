#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,C;
    cin >> N >> C;
    vector<vector<int>>D(C,vector<int>(C));
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < C; j++) {
            cin >> D[i][j];
        }
    }
    vector<vector<int>>c(N,vector<int>(N));
    vector<vector<int>>cnt(3,vector<int>(C));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> c[i][j];
            cnt[(i+j+2)%3][c[i][j]-1]++;
        }
    }
    int ans = INF;
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < C; j++) {
            for(int k = 0; k < C; k++) {
                if(i == j || i == k || j == k) {
                    continue;
                }
                int res = 0;
                for(int l = 0; l < 3; l++) {
                    for(int m = 0; m < C; m++) {
                        if(l == 0) {
                            res += cnt[l][m]*D[m][i];
                        }
                        if(l == 1) {
                            res += cnt[l][m]*D[m][j];
                        }
                        if(l == 2) {
                            res += cnt[l][m]*D[m][k];
                        }
                    }
                }
                ans = min(ans,res);
            }
        }
    }
    cout << ans << endl;
}