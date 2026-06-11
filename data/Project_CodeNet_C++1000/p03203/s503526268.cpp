#include <bits/stdc++.h>

using namespace std;
#define lint long long


int main() {
    int H, W, N;
    cin >> H >> W >> N;
    
    map<int, vector<int>> obs;
    
    for(int i = 0; i < N; ++i){
        int x, y;
        cin >> x >> y;
        obs[x].push_back(y);
    }
    
    for(auto e : obs){
        vector<int> v = e.second;
        sort(v.begin(), v.end());
        obs[e.first] = v;
    }
    
    int M = 1;
    for(int i = 2; i < H + 1; ++i){
        
        auto itl = lower_bound(obs[i].begin(), obs[i].end(), 0);
        
        if(itl == obs[i].end()){
            ++M;
        } else if(*itl < M + 1){
            cout << i - 1 << endl;
            return 0;
        } else if(*itl == M + 1){
            continue;
        } else {
            ++M;
        }
    }
    
    cout << H << endl;
}