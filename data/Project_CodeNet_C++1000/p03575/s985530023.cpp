#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


vector<vector<long long> > G(50, vector<long long>(50, 0)); 
long long n, m;

vector<bool> visit(50, false);

void dfs(long long v){
    visit[v] = true;
    
    for(long long i = 0; i < n; i++){
        if(visit[i] == true) continue;

        if(G[v][i] == 0) continue;

        dfs(i);
    }
}

long long counter(){
    long long cnt = 0;
    for(long long i = 0; i < n; i++){
        if(visit[i] == true) cnt++;
    }
    return cnt;
}

int main(){
    
    cin >> n >> m;

    vector<long long> a(m);
    vector<long long> b(m);

    for(long long i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        G[a[i]][b[i]] = 1;
        G[b[i]][a[i]] = 1;
    }

    long long ans = 0;
    for(long long i = 0; i < m; i++){
        G[a[i]][b[i]] = 0;
        G[b[i]][a[i]] = 0;

        dfs(0);
        if(counter() != n) ans++;

        G[a[i]][b[i]] = 1;
        G[b[i]][a[i]] = 1;
        visit.assign(50, false);
    }

    cout << ans << endl;
    return 0;
}