#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

void dfs(vector<ll> &isVisited, vector<vector<ll> > &vec, vector<vector<pair<ll,ll> > > &length, vector<ll> &color, ll i){
    isVisited[i] = 1;
    for (ll j = 0; j < vec[i].size(); j++){
        if (isVisited[vec[i][j]] == 1){
            continue;
        }
        color[vec[i][j]] = color[i] + length[i][j].second;
        dfs(isVisited, vec, length, color, vec[i][j]);
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
    dfs(isVisited, connection, length, color, 0);
    rep(i,N){
        if (color[i] % 2 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
}
