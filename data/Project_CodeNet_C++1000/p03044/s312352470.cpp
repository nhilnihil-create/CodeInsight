#include<bits/stdc++.h>

#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll = int64_t;

using namespace std;

int n;
vector<pair<int,int>> to[100010];

int dist[100010];

void dfs(int x,int p = -1,int d = 0){
    dist[x] = d;
    for(auto i : to[x]){
       int v = i.first;
       int di = i.second;

       if(v == p)continue;
       dfs(v,x,(d + di) % 2);
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    REP(i,n-1){
        int a,b,c;cin >> a >> b >> c;
        a--,b--;
        to[a].emplace_back(b,c % 2);
        to[b].emplace_back(a,c % 2);
    }
    dfs(0);
    REP(i,n)cout << dist[i] << '\n';
}

