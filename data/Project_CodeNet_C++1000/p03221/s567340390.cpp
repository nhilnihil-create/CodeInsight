#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, ll>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>G(n);
    vector<int>p(m), y(m);
    for(int i=0;i<m;i++){
        cin >> p[i] >> y[i];
        p[i]--;
        G[p[i]].push_back(i);
    }

    vector<ll>ans(m);

    for(ll i=0;i<n;i++){//県順にみる。
        if(G[i].empty()) continue;
        vector<pair<ll, ll>> yy;
        for(auto g:G[i]) yy.push_back({y[g], g});//gは市の番号
        sort(yy.begin(), yy.end());
        for(ll j=0;j < (ll)yy.size();j++){
            ans[yy[j].second] = (i+1)*1000000 + j+1;
        }
    }
    for(int i=0;i<m;i++) printf("%012lld\n", ans[i]);
}