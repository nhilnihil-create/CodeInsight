#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;

    vector<vector<pair<int,int>>> G(n);

    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;    b--;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }

    queue<int> q;
    q.push(0);

    vector<int> ans(n,-1);
    ans[0] = 0;
    while(!q.empty()){
        int now = q.front();    q.pop();

        for(pair<int,int> p: G[now]){
            int next = p.first;
            int dist = p.second;
            if(ans[next]!=-1) continue;

            if(dist%2==1) ans[next] = ans[now]^1;
            else ans[next] = ans[now];

            q.push(next); 
        }
    }
    for(int i=0;i<n;i++) cout << ans[i] << endl;
    return 0;
}