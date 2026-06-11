#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 100000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    vector<P>ab(M);
    for(int i = 0; i < M; i++) {
        cin >> ab[i].first >> ab[i].second;
    }
    sort(ab.begin(),ab.end());
    priority_queue<int,vector<int>,greater<int>> que;
    int ans = 0,now = 0;
    for(int i = 1; i <= N; i++) {
        while(ab[now].first == i) {
            que.push(ab[now].second-1);
            now++;
            if(now == M) {
                goto home;
            }
        }
        if(!que.empty()) {
            int x = que.top();
            if(x == i) {
                ans++;
                while(!que.empty()) {
                    que.pop();
                }
            }
        }
    }
home:;
    if(!que.empty()) {
        ans++;
    }
    cout << ans << endl;
}
