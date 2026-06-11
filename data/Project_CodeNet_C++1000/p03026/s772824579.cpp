#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> G[N];
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> c(N);
    for(int i = 0; i < N; i++) cin >> c[i];
    sort(c.begin(), c.end(), greater<int>());
    queue<int> q;
    q.push(0);
    int now = 0;
    vector<int> score(N);
    score[0] = c[now];
    now++;
    vector<int> used(N);
    int ans = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        used[v] = 1;
        for(int j: G[v]){
            if(used[j] == 0){
                score[j] = c[now];
                now++;
                q.push(j);
                ans += min(score[v], score[j]);
            }
        }
    }
    cout << ans << endl;
    for(int i = 0; i < N; i++){
        if(i != N - 1) cout << score[i] << ' ';
        else cout << score[i] << endl;
    }
}