#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 5e18+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    queue<int>que;
    vector<int>cnt(N),ans(N,-1);
    vector<vector<int>>road(N);
    for(int i = 0; i < N+M-1; i++) {
        int A,B;
        cin >> A >> B;
        A--;B--;
        road[A].push_back(B);
        cnt[B]++;
    }
    for(int i = 0; i < N; i++) {
        if(cnt[i] == 0) {
            que.push(i);
            ans[i] = -1;
        }
    }
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        for(int i = 0; i < road[x].size(); i++) {
            cnt[road[x][i]]--;
            if(cnt[road[x][i]] == 0) {
                que.push(road[x][i]);
                ans[road[x][i]] = x;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        cout << ans[i]+1 << endl;
    }
}
