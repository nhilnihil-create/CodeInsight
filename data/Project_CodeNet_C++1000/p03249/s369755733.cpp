#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
void no(){
    cout << -1 << endl;
    exit(0);
}
vector<int> ans[100005];
bool paint[100005] = {};
lli n;
lli par[100005] = {};
lli tree_size[100005] = {};
lli tmp[100005] = {};
lli dp[100005] = {};
lli very[100005] = {};
lli fi(int u,int p){
    for(auto s:ans[u]){
        if(s != p){
            dp[u] += fi(s, u) + tree_size[s];
        }
    }
    very[u] = dp[u];
    return dp[u];
}
void calc(int u,int p){
    if(u!=0){
        very[u] = very[p] + n - 2 * tree_size[u];
    }
    for(auto s:ans[u]){
        if(p!=s)
            calc(s, u);
    }
}
lli recalc_size(int u, int p){
    tree_size[u] = 1;
    for(auto s:ans[u]){
        if(s==p)continue;
        tree_size[u] += recalc_size(s,u);
    }
    //cout << u << " " << tree_size[u] << endl;
    return tree_size[u];
}
void check_and_emit(){
    rep(i,n){
        if(par[i]!=-1)
        {
            ans[i].push_back(par[i]);
            ans[par[i]].push_back(i);
        }
    }
    recalc_size(0,-1);
    fi(0,-1);
    calc(0,-1);
    rep(i,n){
        if(very[i] != tmp[i]){
            no();
        }
    }
    rep(i,n){
        for(auto s:ans[i]){
            if(s>i)
            cout << i+1 << " " << s+1 << endl;
        }
    }
}



int main() {
    cin >> n;
    vector<pair<lli,lli>> d(n);
    map<lli,lli> m;
    rep(i,n){
        cin >> d[i].first,d[i].second = i;
        tmp[i] = d[i].first;
        m[d[i].first] = i;
        par[i] = -1;
    }
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    vector<bool> used(n);
    if(n==2){
        cout << -1 << endl;
        return 0;
    }
    rep(i,n)tree_size[i] = 1;
    rep(i,n-1){
        int cur = d[i].second;
        // 現在のcurが属する部分木の大きさ
        lli next = d[i].first - n + 2 * tree_size[cur];
        //cout << next << endl;
        if(next >= d[i].first ){
            no();
        }else {
            if(m.find(next) == m.end()){
                no();
            }
            par[cur] = m[next];
            tree_size[m[next]] += tree_size[cur];
        }
    }
    check_and_emit();
}
