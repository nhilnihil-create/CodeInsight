#include<bits/stdc++.h>
using namespace std;

#define p_ary(ary,a,b,i) do { cout << "["; for (int i = a;i <= b;++i) cout << ary[i] << (b == i ? "]\n" : ", "); } while(0)
#define p_map(map,it) do {cout << "{";for (auto it = map.begin();;++it) {if (it == map.end()) {cout << "}\n";break;}else cout << "" << it->first << "=>" << it->second << ", ";}}while(0)

typedef pair<int, int> P;

int main() {
    int h,w,n,x,y;
    vector<vector<int>> obs(200010);
    vector<P> xy;
    map<P,bool> is_obs;

    cin >> h >> w >> n;
    for (int i = 0;i < n;++i) {
        cin >> x >> y;
        xy.push_back(P(x,y));
    }
    sort(xy.begin(),xy.end());
    for (int i = 0;i < n;++i) {
        obs[xy[i].second].push_back(xy[i].first);
        is_obs[xy[i]] = true;
    }
    for (int i = 1;i <= h;++i) is_obs[P(i,w+1)] = true;
    for (int i = 1;i <= w;++i) {
        obs[i].push_back(h+1);
        is_obs[P(h+1,i)] = true;
    }

    int i = 0,ans = 1000000;
    x = 1;y = 1;
    while (1) {
        if (i%2) {
            int m = *lower_bound(obs[y].begin(),obs[y].end(),x);
            ans = min(ans,m-1);
            if (!is_obs[P(x,y+1)]) y++;
        } else {
            if (is_obs[P(x+1,y)]) {
                ans = min(ans,x);
                break;
            }
            x++;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}