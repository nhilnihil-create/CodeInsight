#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector <int> ans(n,-1);
    ans[0]=0;
    vector <vector <ll>> m(n),d(n);

    ll u,v,w;
    rep(i,n-1){
        cin >> u >> v >> w;
        --u;
        --v;
        m[u].push_back(v);
        d[u].push_back(w);
        m[v].push_back(u);
        d[v].push_back(w);
    }

    ll l;
    queue <ll> q;
    ll qq;
    q.push(0);

    while(q.size()!=0){
        qq=q.front();
        q.pop();
        l=m[qq].size();
        rep(i,l){
            if(ans[m[qq][i]]==-1){
                ans[m[qq][i]]=(ans[qq]+d[qq][i])%2;
                q.push(m[qq][i]);
            }
        }
    }

    rep(i,n){
        cout << ans[i] << endl;
    }
    

    return 0;
}