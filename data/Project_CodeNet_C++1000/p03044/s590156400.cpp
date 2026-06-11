#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<vector<pair<int,int>>> &path, vector<int> &color, int now){
    int c = color.at(now);
    for(int i=0; i<path.at(now).size(); i++){
        pair<int,int> p = path.at(now).at(i);
        int next,dist;
        next = p.first;
        dist = p.second;
        if(color.at(next) != -1) continue;
        if(dist%2==0) color.at(next) = c;
        else color.at(next) = 1-c;
        dfs(path, color, next);
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> path(n);
    for(int i=0; i<n-1; i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        pair<int,int> p;
        p=make_pair(v,w);
        path.at(u).push_back(p);
        p=make_pair(u,w);
        path.at(v).push_back(p);
    }
    vector<int> color(n,-1);
    color.at(0) = 0;
    dfs(path, color,0);
    for(int i=0; i<n; i++){
        cout << color.at(i) << endl;
    }
}
