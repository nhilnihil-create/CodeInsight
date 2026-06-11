#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
void dfs(ll v,ll par,set<ll> &st,vl &ans, vvl &g){
    for(auto nv:g[v]){
        if(ans[nv]==-1){
            ans[nv]=v;
            st.insert(v);dfs(nv,v,st,ans,g);st.erase(v);
        }
        else{
            if(st.count(ans[nv]))ans[nv]=v;
        }
    }
}
int main(){
    ll n,m;cin >>n >>m;
    vvl g(n);
    vl ans(n,-1);
    set<ll> st;rep(i,n)st.insert(i);
    rep(i,n-1+m){
        ll a,b;cin >> a >> b;a--;b--;
        g[a].push_back(b);
        st.erase(b);
    }
    ll s=*st.begin();st.clear();
    dfs(s,-1,st,ans,g);
    for(auto p:ans)cout << p+1 <<endl;
} 