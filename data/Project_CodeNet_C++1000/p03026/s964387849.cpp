#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n; cin>>n;
    vector<vector<ll>> tree(n+1);
    rep(i,n-1){
        ll a,b; cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<ll> c(n);
    vector<bool> used(n+1, false);
    ll M=0;
    rep(i,n){
        cin>>c[i];
        M+=c[i];
    }
    sort(c.begin(), c.end(), greater<ll>());
    cout<<M-c[0]<<endl;
    vector<ll> res(n+1);
    queue<ll> que;
    que.push(1);
    ll tmp=0;
    while(!que.empty()){
        ll x=que.front();
        used[x]=true;
        res[x]=c[tmp];
        tmp++;
        que.pop();
        for(ll y:tree[x]){
            if(used[y]) continue;
            used[y]=true;
            que.push(y);
        }
    }
    for(ll i=1; i<=n; i++) cout<<res[i]<<' ';
    cout<<endl;
    return 0;
}