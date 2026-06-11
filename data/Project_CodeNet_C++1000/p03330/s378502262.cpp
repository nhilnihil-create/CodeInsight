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
    vector<vector<int>>cnt(3,vector<int>(C));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int c;
            cin >> c;
            c--;
            cnt[(i+j)%3][c]++;
        }
    }
    int ans = INF;
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < C; j++) {
            for(int k = 0; k < C; k++) {
                if(i == j || j == k || i == k) {
                    continue;
                }
                int sum = 0;
                for(int l = 0; l < C; l++) {
                    sum += D[l][i]*cnt[0][l];
                    sum += D[l][j]*cnt[1][l];
                    sum += D[l][k]*cnt[2][l];
                }
                ans = min(ans,sum);
            }
        }
    }
    cout << ans << endl;
}
