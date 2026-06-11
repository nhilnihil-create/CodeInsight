#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

ll poll(pair<ll,ll> s,pair<ll,ll> g){
    return abs(s.first-g.first)+abs(s.second-g.second);
}

int main(){
    ll h,w,d;
    cin >> h >> w >> d;
    map<ll,pair<ll,ll>> mp;
    map<pair<int,int>,int> dp;
    map<pair<int,int>,bool> flag;
    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; j++){
            ll a;
            cin >> a;
            mp[a] = {i,j};
        }
    }

    for(int i = d+1; i <= w*h; i++){
        dp[mp[i]] = dp[mp[i-d]]+poll(mp[i],mp[i-d]);
    }
    int q;
    cin >> q;
    vector<int> ans;
    for(int i = 0; i < q; i++){
        int l,r;
        cin >> l >> r;
        ans.push_back(dp[mp[r]]-dp[mp[l]]);
    }
    for(auto p:ans){
        cout << p << endl;
    }
}