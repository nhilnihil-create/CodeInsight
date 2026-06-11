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
    VS s(H);
    rep(i, 0, H) cin >> s[i];
    rep(h, 0, H){
        rep(w, 0, W){
            if(s[h][w] == '.') continue;
            bool tf = false;
            rep(i, 0, 4){
                ll nh = h + d1[i];
                ll nw = w + d2[i];
                if(nh < 0 || nw < 0 || nh >= H || nw >= W) continue;
                if(s[nh][nw] == '#') tf = true;
            }
            if(!tf){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}