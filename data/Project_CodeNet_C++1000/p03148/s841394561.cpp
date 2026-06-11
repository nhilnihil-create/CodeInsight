#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL<<40;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> s(n);
    rep(i,n){
        int t, d; 
        cin >> t >> d;
        --t;
        s[t].pb(d);
    }
    for(auto &v : s){
        sort(ALL(v), greater<ll>());
        if(v.empty()) v.push_back(-INF);
    }
    sort(ALL(s),[&](vector<ll> a, vector<ll> b){return a[0] > b[0];});//s[0]を降順に

    ll cur = 0;
    priority_queue<ll> que;//curに入っていないものを全部いれる
    for(int i = 0; i < k; i++){
        cur += s[i][0];
        for(int j = 1; j < s[i].size(); j++) que.push(s[i][j]);
    }
    for(int i = k; i < n; i++) for(int j = 0; j < s[i].size(); j++) que.push(s[i][j]);
    ll res = cur + k * k;
    for(ll x = k - 1; x >= 1; x--){
        ll v = s[x][0];
        ll w = que.top();
        if(v < w){
            que.pop(); cur += w;
            que.push(v);//!!
            cur -= v;
        }
        res = max(res, cur + x * x);//二乗するときintに収まらない可能性に注意
    }
    cout << res << endl;
}