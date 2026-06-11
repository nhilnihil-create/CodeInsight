#include <iostream>
#include <vector>
#include <deque>

using namespace std;
typedef long long ll;

int main(){
    ll k;
    cin >> k;
    vector<vector<pair<ll, ll>>> net(k);
    for(ll i = 0; i < k; ++i){
        net.at(i).push_back(make_pair((i + 1) % k, 1));
        net.at(i).push_back(make_pair((i * 10) % k, 0));
    }

    vector<ll> ans(k, 0);
    vector<bool> visited(k, false);
    ans.at(1) = 1;
    visited.at(1) = true;
    deque<ll> q;
    q.push_front(1);
    while(!q.empty() && !visited.at(0)){
        ll x = q.front();
        q.pop_front();
        for(auto p : net.at(x)){
            if(visited.at(p.first)){ continue; }
            if(p.second){
                ans.at(p.first) = ans.at(x) + 1;
            }else{
                ans.at(p.first) = ans.at(x);
                q.push_front(p.first);
            }
            q.push_back(p.first);
            visited.at(x) = true;
        }
    }
    cout << ans.at(0) << endl;

    return 0;
}