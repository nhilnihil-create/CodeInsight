#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> graph(n);
    vector<ll> iri(n,0);
    for(i = 0;i < n+m-1;++i){
        ll a,b;
        cin >> a >> b;
        --a;    --b;
        graph.at(a).push_back(b);
        ++iri.at(b);
    }
    queue<ll> que;
    vector<ll> vdis(n,-1);
    ll top;
    for(i = 0;i < n;++i){
        if(iri.at(i) == 0){
            top = i;
            break;
        }
    }
    vdis.at(top) = 0;
    que.emplace(top);
    while(!que.empty()){
        ll now = que.front();
        que.pop();
        for(i = 0;i < graph.at(now).size();++i){
            ll next = graph.at(now).at(i);
            if(iri.at(next) > 1){
                --iri.at(next);
            }else{
                vdis.at(next) = now+1;
                que.emplace(next);
            }
        }
    }
    for(i = 0;i < n;++i){
        cout << vdis.at(i) << endl;
    }

    return 0;
}