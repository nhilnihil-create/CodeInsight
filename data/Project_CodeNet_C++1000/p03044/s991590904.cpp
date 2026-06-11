#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

void bfs(queue<ll> que, vector<ll> &isVisited, vector<vector<ll> > &vec, vector<vector<pair<ll,ll> > > &length, vector<ll> &color){
    que.push(0);
    isVisited[0] = 1;
    while(que.size() != 0){
        ll q = que.front();
        rep(i,vec[q].size()){
            if (isVisited[vec[q][i]] == 0){
                que.push(vec[q][i]);
                color[vec[q][i]] = color[q] + length[q][i].second;
                isVisited[vec[q][i]] = 1;
            }
        }
        que.pop();
    }
}

int main(){
    ll N;
    cin >> N;
    vector<ll> color(N,0);
    vector<ll> isVisited(N,0);
    vector<vector<pair<ll,ll> > > length(N, vector<pair<ll,ll> > (0));
    vector<vector<ll> > connection(N,vector<ll> (0));
    rep(i,N - 1){
        ll u,v,w;
        cin >> u >> v >> w;
        connection[u - 1].push_back(v - 1);
        connection[v - 1].push_back(u - 1);
        length[u - 1].push_back(pair<ll,ll> (v - 1, w));
        length[v - 1].push_back(pair<ll,ll> (u - 1, w));
    }
    queue<ll> que;
    bfs(que, isVisited, connection, length, color);
    rep(i,N){
        if (color[i] % 2 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
}
