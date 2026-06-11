#include<bits/stdc++.h>

#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};
typedef pair<int, int> PII;

int main() {
    int h, w;
    cin >> h >> w;
    int num_brack = 0;
    vector<string> grah(h);
    for(int i = 0; i < h; i++){
        cin >> grah.at(i);
    }
    rep(i, h) rep(j, w){
        if(grah.at(i).at(j) == '#') num_brack++;
    }
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<PII> q;
    q.emplace(0, 0);
    dist.at(0).at(0) = 0;

    while(!q.empty())
    {
        auto v = q.front();
        q.pop();
        rep(i, 4){
            int ny = v.first + dy.at(i);
            int nx = v.second + dx.at(i);
            if(0 <= ny && 0 <= nx && ny < h  && nx < w  && dist.at(ny).at(nx) == -1 && grah.at(ny).at(nx) != '#'){
                dist.at(ny).at(nx) = dist.at(v.first).at(v.second) + 1;
                q.emplace(ny, nx);
            }
        }
    }
    auto size = 0;
    rep(i, h){
        size += grah.at(i).size();
    }
    if(dist.at(h-1).at(w-1) == -1) {
        cout << "-1" << endl;
        return 0;
    }
    cout << size - num_brack - (dist.at(h-1).at(w-1) + 1) << endl;
    
    return 0;

}