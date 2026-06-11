#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()
 
ll n;
ll a[100010], b[100010];
vector<ll> c;
struct  choten{
    ll weight;
    vector<ll> child;
};
choten g[100010];
bool used[100010] = {false};
void dfs(ll p){
    g[p].weight = c.back();
    c.pop_back();
    used[p] = true;
    rep(i, g[p].child.size()){
        ll c = g[p].child[i];
        if(used[c])continue;
        dfs(c);
    }
}
int main(){
    cin >> n;
    rep(i, n-1){
        cin >> a[i] >> b[i];
        g[a[i]].child.push_back(b[i]);
        g[b[i]].child.push_back(a[i]);
    }
    rep(i, n){
        ll c_i;
        cin >> c_i;
        c.push_back(c_i);
    }
    sort(ALL(c));
    ll sum = 0;
    rep(i, n-1)sum+=c[i];
    cout << sum << endl;
    dfs(a[0]);
    rep(i, n) cout << g[i+1].weight << " ";
}