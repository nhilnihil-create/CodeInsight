#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> G[10010];
vector<int> c;
bool flag[10010];
int ans[10010];
int main(){
    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int sum = 0;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        sum += x;
        c.push_back(x);
    }
    sort(c.rbegin(), c.rend());
    queue<int> q;
    q.push(1);
    flag[1] = true;
    int idx = 0;
    while(!q.empty()){
        int a = q.front();
        ans[a] = c[idx++];
        q.pop();
        for(int i = 0; i < G[a].size(); i++){
            int g = G[a][i];
            if(!flag[g]){
                flag[g] = true;
                q.push(g);
            }
        }
    }
    cout << sum - c[0] << endl;
    for(int i = 1; i <= N; i++){
        cout << ans[i] << (i != N ? " " : "\n");
    }
    cout << endl;
    return 0;
}