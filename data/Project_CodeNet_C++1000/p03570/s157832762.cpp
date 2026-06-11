#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
const ll INF = 5e15;

int main(){
    string s;
    cin >> s;
    map<ll, ll> ma;
    ma[0] = 0;
    vector<ll> nodes;
    for(ll i = 0; i < s.size(); i++){
        ll tmp = (nodes.size() ? nodes[nodes.size() - 1] : 0);
        nodes.push_back(tmp ^ (1 << (s[i] - 'a')));
    }
    vector<ll> d(nodes.size(), INF);
    for(ll i = 0; i < nodes.size(); i++){
        ll dis = INF;
        for(ll j = -1; j < 26; j++){
            ll tmp = nodes[i];
            if(j != -1) tmp ^= (1 << j);
            auto ite = ma.find(tmp);
            if(ite != ma.end()) dis = min(dis, ite->second);
        }
        d[i] = dis + 1;
        if(ma.find(nodes[i]) == ma.end()) ma[nodes[i]] = d[i];
        else ma[nodes[i]] = min(ma[nodes[i]], d[i]);
    }
    cout << d[d.size() - 1] << endl;
    return 0;
}
