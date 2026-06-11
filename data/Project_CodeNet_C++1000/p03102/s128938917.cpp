#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M,C;
    cin >> N >> M >> C;
    vector<int>B(M);
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }
    vector<vector<int>>A(N,vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < M; j++) {
            cnt+=B[j]*A[i][j];
        }
        if(cnt+C > 0) {
            ans++;
        }
    }
    cout << ans << endl;
}
