#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M,C;
    cin >> N >> M >> C;
    vector<int>B(M);
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int res = 0;
        for(int j = 0; j < M; j++) {
            int A;
            cin >> A;
            res += A*B[j];
        }
        res += C;
        if(res > 0) {
            ans++;
        }
    }
    cout << ans << endl;
}

