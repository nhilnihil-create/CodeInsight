#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(){
    ll h, w, d;
    cin >> h >> w >> d;
    vector<vector<ll>> g(h*w+1);
    map<ll, p> I{};
    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; j++){
            ll a;
            cin >> a;
            I[a] = p(i,j);
        }
    }
    vector<vector<ll>> sum(d+1);
    for(ll i = 1; i <= d; i++){
        sum[i].push_back(0);
        for(ll j = i+d; j <= h*w; j+=d){
            ll c = abs(I[j].first-I[j-d].first)+abs(I[j].second-I[j-d].second)+sum[i][sum[i].size()-1];
            sum[i].push_back(c);
        }
    }
    ll q;
    cin >> q;
    vector<ll> ans;
    for(ll i = 0; i < q; i++){
        ll check = 0;
        ll l, r;
        cin >> l >> r;
        if(l<d) check = sum[l][(r/d)]-sum[l][(l/d)];
        else if(l>=d && l%d==0)
            check = sum[d][r/d-1]-sum[d][l/d-1];
        else if(l>=d && l%d!=0)
            check = sum[l%d][r/d]-sum[l%d][l/d];
        ans.push_back(check);
    }
    for(ll i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    /*for(ll i = 1; i <= d; i++){
        for(ll j = 0; j <sum[i].size(); j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }*/
    return 0;
}
