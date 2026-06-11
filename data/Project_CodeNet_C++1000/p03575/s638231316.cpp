#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long n, m;
vector<vector<long long> > v(50, vector<long long> (50, 0));

vector<bool> visit(50, false);

void init(){
    for(long long i = 0; i < 50; i++) visit[i] = false;
}

void dfs(long long x){
    if(visit[x] == true) return;

    visit[x] = true;

    for(long long i = 0; i < n; i++){
        if(v[x][i] == 1) dfs(i);
    }
}

int main(){
    cin >> n >> m;

    vector<pair<long long, long long> > edges; 
    for(long long i = 0; i < m; i++){
        long long a, b;
        cin >> a >> b;
        a--;
        b--;
        edges.push_back(make_pair(a, b));
        v[a][b] = 1;
        v[b][a] = 1;
    }

    long long cnt = 0;
    for(long long i = 0; i < m; i++){
        long long a, b;
        a = edges[i].first;
        b = edges[i].second;
        v[a][b] = 0;
        v[b][a] = 0;
        dfs(0);

        bool flag = true;
        for(long long i = 0; i < n; i++){
            if(visit[i] == false) flag = false;
        }

        if(flag == false) cnt++;

        init();
        v[a][b] = 1;
        v[b][a] = 1;
    }

    cout << cnt << endl;
    return 0;
}