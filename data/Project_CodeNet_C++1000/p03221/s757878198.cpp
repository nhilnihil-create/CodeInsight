#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

using ll = long long;

int main(void){
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> vv(N);
    for (int i=0; i<M; i++){
        int p, y;
        cin >> p >> y;
        p--;
        vv[p].emplace_back(y, i);
    }
    vector<pair<int, int>> ans(M);
    for (int i=0; i<N; i++){
        sort(vv[i].begin(), vv[i].end());
        for (int j=0; j<vv[i].size(); j++){
            int index = vv[i][j].second;
            ans[index] = make_pair(i+1, j+1);
        }
    }
    
    for (int i=0; i<M; i++){
        printf("%06d%06d\n", ans[i].first, ans[i].second);
    }
    
}
