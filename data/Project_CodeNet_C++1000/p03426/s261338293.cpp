#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll H,W,D;
    cin >> H >> W >> D;
    vector<vector<ll> >  grid(H, vector<ll>(W));
    vector<pair<ll,ll> > grid_state(H * W + 1);
    rep(i,H){
        rep(j,W){
            cin >> grid[i][j];
            grid_state[grid[i][j]].first = i + 1;
            grid_state[grid[i][j]].second = j + 1;
        }
    }
    ll Q;
    cin >> Q;
    vector<pair<ll,ll> > test(Q);
    rep(i,Q){
        cin >> test[i].first >> test[i].second;
    }
    vector<ll> magic_power(H * W + 1);
    for (ll i = 0; i <= D; i++){
        magic_power[i] = 0;
    }
    for (ll i = D + 1; i <= H * W; i++){
        magic_power[i] = magic_power[i - D] + abs(grid_state[i].first - grid_state[i - D].first) + abs(grid_state[i].second - grid_state[i - D].second);
    }
    rep(i,Q){
        cout << magic_power[test[i].second] - magic_power[test[i].first] << endl;
    }
}
