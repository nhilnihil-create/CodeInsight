#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int h, w, d; cin >> h >> w >> d;
    vector<vector<pair<int, pair<int, int>>>> mp(d);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int a; cin >> a;
            mp[a % d].push_back({a, make_pair(i,j)});
        }
    }
    for(int i = 0; i < d; i++){
        sort(mp[i].begin(), mp[i].end());
    }
    vector<vector<int>> sum(d);
    for(int i = 0; i < d; i++){
        sum[i].push_back(0);
        int x = mp[i][0].second.first, y = mp[i][0].second.second;
        for(int j = 1; j < mp[i].size(); j++){
            int nx = mp[i][j].second.first, ny = mp[i][j].second.second;
            sum[i].push_back(abs(nx - x) + abs(ny - y) + sum[i][j-1]);
            x = nx; y = ny;
        }
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        cout << sum[r%d][(r-1)/d] - sum[l%d][(l-1)/d]  << endl;
    }
}