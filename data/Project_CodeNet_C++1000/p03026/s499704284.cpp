#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<vector<ll>> tree;
vector<ll> c;
vector<ll> ans;
queue<ll> q;


void dfs(ll t,ll p){
    ll n = q.front();q.pop();
    ans[t] = n;
    for(ll child:tree[t]){
        if(child == p){
            continue;
        }
        dfs(child,t);
    }

}

int main() {
    ll N;
    cin >> N;
    tree.resize(N);
    for(int i=0;i<N-1;i++){
        ll a,b;
        cin >> a >> b;
        --a;--b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    c.resize(N);
    for(int i=0;i<N;i++){
        cin >> c[i];
    }
    sort(c.rbegin(),c.rend());
    ll num =0;
    q.push(c[0]);
    for(int i=1;i<N;i++){
        num += c[i];
        q.push(c[i]);
    }
    cout << num << endl;
    ans.resize(N);
    dfs(0,-1);
    for(int i=0;i<N;i++){
        cout << ans[i] <<" ";
    }
    cout << endl;


    return 0;
}