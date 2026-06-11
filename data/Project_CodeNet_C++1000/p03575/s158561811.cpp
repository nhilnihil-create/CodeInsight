#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

vector<bool> seen;
vector<vector<ll>> g;

void dfs(ll x){

    seen[x] = 1;

    ll L = g[x].size();

    rep(i, 0, L){

        if(seen[g[x][i]])continue;

        dfs(g[x][i]);

    }

}

int main(){
ll N, M, Ans = 0;cin >> N >> M;
vector<pair<ll, ll>> A(M);
seen.resize(N + 1);
g.resize(N  + 1);

rep(i, 0, M){

    ll a, b;cin >> a >> b;

    A[i].first = a;A[i].second = b;

    g[a].push_back(b);g[b].push_back(a);

}

rep(i, 0, M){

    rep(i, 1, N + 1)seen[i] = 0;

    ll a = A[i].first, b = A[i].second;

    g[a].erase(remove(g[a].begin(), g[a].end(), b), g[a].end());
    g[b].erase(remove(g[b].begin(), g[b].end(), a), g[b].end());

    dfs(1);

    rep(i, 1, N + 1){

        if(!seen[i]){Ans++;break;}

    }

    g[a].push_back(b);g[b].push_back(a);
    
}

cout << Ans;

}