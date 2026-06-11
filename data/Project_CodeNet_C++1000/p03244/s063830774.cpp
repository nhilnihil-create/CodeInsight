#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main() {
    int n;cin >>n;
    map<int,int>odd;
    map<int,int>even;
    for (int i = 0; i < n; ++i) {
        int v;cin >>v;
        if(i%2==0)even[v]++;
        else odd[v]++;
    }
    vector<pair<int,int>>op;
    vector<pair<int,int>>ep;
    for(auto p:odd){
        op.push_back({p.second,p.first});
        op.push_back({0,0});
    }
    for(auto p:even){
        ep.push_back({p.second,p.first});
        ep.push_back({0,0});
    }
    sort(all(op));
    reverse(all(op));
    sort(all(ep));
    reverse(all(ep));
    int ans=0;
    if(op[0].second==ep[0].second){
        ans=min(n-ep[1].first-op[0].first,n-ep[0].first-op[1].first);
    }
    else {
        ans=n-ep[0].first-op[0].first;
    }
    cout <<ans <<endl;
    return 0;
}

