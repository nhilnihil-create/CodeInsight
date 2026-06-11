//https://agc027.contest.atcoder.jp/tasks/agc027_c

#include<bits/stdc++.h>
const int N = 2e5 + 5;
using namespace std;

queue <int> mq;
vector <int> adj[N];
int n, m, cnt[N][2], num;
string s;
bool dead[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s; s = '.' + s;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); cnt[u][s[v]-'A']++;
        adj[v].push_back(u); cnt[v][s[u]-'A']++;
    }
    for (int u = 1; u <= n; u++) {
        if (!cnt[u][0] || !cnt[u][1]) {
            mq.push(u);
            dead[u] = true;
        }
    }
    while (mq.size()){
        int u = mq.front(); mq.pop();
        num++;
        for (auto v : adj[u]){
            if (dead[v]) continue;
            cnt[v][s[u]-'A']--;
            if (!cnt[v][s[u]-'A']){
                mq.push(v);
                dead[v] = true;
            }
        }
    }
    cout << ((num == n) ? "No" : "Yes");
}
