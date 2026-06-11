#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<int> cnt(N), score(N);
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cnt[a]++;
        cnt[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> c(N);
    for(int i = 0; i < N; i++) cin >> c[i];
    sort(c.begin(), c.end());
    vector<int> ind(N);
    for(int i = 0; i < N; i++) ind[i] = i;
    sort(ind.begin(), ind.end(), [&](int i, int j){
        return cnt[i] < cnt[j];
    });
    priority_queue<P> q;
    vector<int> used(N, 0);
    q.push(P(cnt[ind[N - 1]], ind[N - 1]));
    int now = N - 1;
    while(!q.empty()){
        P v = q.top();
        used[v.second] = 1;
        q.pop();
        score[v.second] = c[now];
        now--;
        for(int j: G[v.second]){
            if(used[j] != 1){
                q.push(P(cnt[j], j));
            }
        }
    }
    queue<int> pq;
    pq.push(0);
    used.assign(N, 0);
    int ans = 0;
    while(!pq.empty()){
        int v = pq.front();
        pq.pop();
        used[v] = 1;
        for(int j: G[v]){
            if(used[j] == 0){
                ans += min(score[v], score[j]);
                pq.push(j);
            }
        }
    }
    cout << ans << endl;
    for(int i = 0; i < N; i++){
        if(i != N - 1) cout << score[i] << ' ';
        else cout << score[i] << endl;
    }
}