#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,T;
    cin >> N >> T;
    int ans = INF;
    for(int i = 0; i < N; i++) {
        int c,t;
        cin >> c >> t;
        if(t <= T) {
            ans = min(ans,c);
        }
    }
    if(ans == INF) {
        cout << "TLE" << endl;
    }
    else {
        cout << ans << endl;
    }
}