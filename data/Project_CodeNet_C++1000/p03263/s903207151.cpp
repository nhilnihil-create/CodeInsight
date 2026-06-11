#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

struct mv{
    ll x, y, z, w;
};

int main(){
    ll h, w;
    cin >> h >> w;
    ll a[h][w];
    rep(i, h)rep(j, w){
        cin >> a[i][j];
    }

    vector<mv> ans;
    ll sum = 0;
    ll x, y;
    x = y = 0;
    bool direc = true;

    while(true){
        ll nxt_y, nxt_x;
        nxt_y = y;
        if(direc)nxt_x = x+1;
        else nxt_x = x-1;
        
        if(nxt_x >= w || nxt_x < 0){
            nxt_y++;
            nxt_x = x;
            direc = !direc;
        }

        sum += a[y][x];
        
        if(nxt_y >= h)break;
        if(sum & 1)ans.push_back(mv({x+1, y+1, nxt_x+1, nxt_y+1}));

        x = nxt_x, y = nxt_y;
    }

    cout << ans.size() << endl;
    rep(i, ans.size()){
        cout << ans[i].y << " " << ans[i].x << " " << ans[i].w << " " << ans[i].z << endl;
    }
}