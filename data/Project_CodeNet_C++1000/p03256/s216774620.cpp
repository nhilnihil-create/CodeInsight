#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;
    vector<vector<int>> G(N);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        if(a != b)
            G[b].push_back(a);
    }

    vector<int> as(N, 0);
    vector<int> bs(N, 0);
    for(int i=0; i<N; i++){
        for(int t : G[i]){
            if(s[t] == 'A') as[i]++;
            else bs[i]++;
        }
    }

    vector<bool> vis(N, false);

    int cnt = 0;
    queue<int> dead;
    for(int i=0; i<N; i++){
        if(as[i] == 0 || bs[i] == 0){
            dead.push(i);
            vis[i] = true;
        }
    }

    cnt = dead.size();
    while(!dead.empty()){
        int i = dead.front();
        dead.pop();
        for(int t : G[i]){
            if(vis[t]) continue;
            if(s[i] == 'A') as[t]--;
            else bs[t]--;
            if(as[t] == 0 || bs[t] == 0){
                dead.push(t);
                vis[t] = true;
                cnt++;
            }
        }
    }
    cout << (cnt < N ? "Yes" : "No") << endl;
    return 0;
}
