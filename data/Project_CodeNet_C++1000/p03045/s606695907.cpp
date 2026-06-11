#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge{
    int to,dist;
};

int main(void){
    int n,m;
    cin >> n >> m;

    vector<vector<edge>> G(n);
    vector<int> dig(n,-1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--; c %= 2;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }

    int count = 0;
    for(int i=0;i<n;i++){
        if(dig[i]!=-1) continue;

        count++;
        queue<int> q;
        q.push(i);
        dig[i] = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int j=0;j<G[cur].size();j++){
                int np = G[cur][j].to;
                int dif = G[cur][j].dist;

                if(dig[np]!=-1) continue;

                dig[np] = (dig[cur]+dif)%2;
                q.push(np);
            }
        }
    }
    cout << count << endl;
    return 0;
}