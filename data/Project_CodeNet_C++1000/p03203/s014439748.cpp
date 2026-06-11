#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> v(h+1, w+1);
    vector<pair<int,int>> obstacles;
    for(int i=0;i<n;++i){
        int x, y;
        cin >> x >> y;
        v[x] = min(v[x], y);
        obstacles.emplace_back(x, y);
    }

    vector<int> range(h+1);
    for(int x=2,y=1;x<=h;++x){
        if(v[x] > y+1)y++;
        range[x] = y;
    }

    int ans = h;
    for(auto e: obstacles){
        if(e.second <= range[e.first])ans = min(ans, e.first-1);
    }

    cout << ans << endl;

    return 0;
}
