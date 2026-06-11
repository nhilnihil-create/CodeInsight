#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dp[55][55][5000];
signed main() {
    vector<int>cnt(4);
    for(int i = 0; i < 3; i++) {
        int a,b;
        cin >> a >> b;
        cnt[a-1]++;
        cnt[b-1]++;
    }
    for(int i = 0; i < 4; i++) {
        if(cnt[i] == 3) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
