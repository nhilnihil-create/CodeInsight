#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<vector<int>>vec(N,vector<int>(10));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> vec[i][j];
        }
    }
    vector<vector<int>>P(N,vector<int>(11));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 11; j++) {
            cin >> P[i][j];
        }
    }
    int ans = -1000000000000;
    for(int bit = 1; bit < (1 << 10); bit++) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            int sum = 0;
            for(int j = 0; j < 10; j++) {
                if(((bit>>j)&1) && vec[i][j]) {
                    sum++;
                }
            }
            cnt += P[i][sum];
        }
        if(cnt > ans) {
            ans = cnt;
        }
    }
    cout << ans << endl;
}