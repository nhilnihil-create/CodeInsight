#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll H, W;
    cin >> H >> W;
    VVL a(H, VL(W));
    rep(h, 0, H){
        rep(w, 0, W) cin >> a[h][w];
    }
    vector<vector<ll>> ans;
    rep(h, 0, H){
        rep(w, 0, W-1){
            if(a[h][w] % 2 == 1){
                a[h][w+1]++;
                ans.push_back({h, w, h, w+1});
            }
        }
    }
    rep(h, 0, H-1){
        if(a[h][W-1] % 2 == 1){
            a[h+1][W-1]++;
            ans.push_back({h, W-1, h+1, W-1});
        }
    }
    cout << ans.size() << endl;
    for(auto e : ans){
        rep(i, 0, 4){
            cout << e[i]+1;
            if(i == 3) cout << "\n";
            else cout << " ";
        }
    }
    return 0;
}