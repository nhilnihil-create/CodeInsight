#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}

vector<vector<ll>> g;
vector<ll> memo;
ll ind = 0;
vector<ll> c, t;
ll tot = 0;
ll dfs(ll v, ll p, ll& ind){
    if(memo[v]) return 0;
    memo[v] = c[ind++];
    if(p != -1){
        tot += min(memo[v],memo[p]);
    }
    for(auto& u:g[v]){
        dfs(u,v,ind);
    }
}


int main(){
    ll N, a, b;
    cin >> N;
    vector<Pll> h(N);
    
    g = vector<vector<ll>>(N);
    memo = vector<ll>(N);
    c = vector<ll>(N);
    //d = vector<ll>(N);

    rep(i,N-1){
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    rep(i,N){
        cin >> c[i];
    }
    sort(c.begin(),c.end(),greater<ll>());
    dfs(0,-1,ind);
    cout << tot << endl;
    PR(memo,N);
    /*ll tot = 0;
    rep(i,N){
        tot += c[i];
    }
    tot -= c[0];
    cout << tot << endl;
    
    /*
    rep(i,N){
        h[i] = Pll(g[i].size(), i);
    }
    sort(h.begin(),h.end(),greater<Pll>());
    ll tot = 0;
    ll cur = 0;
    rep(i,N){
        if(cur >= N) break;
        rep(j,g[h[cur].second].size()){
            if(t[g[h[cur].second][j]] != 0){
                t[g[h[cur].second][j]] = c[i];
                i++;
            }
        }
        t[h[cur].second] = c[i];
        cur++;
        //tot += c[i]*h[i].first;
    }
    rep(i,N){
        rep(j,g[i].size()){
            tot += min(t[i], t[g[i][j]]);
        }
    }
    cout << tot/2 << endl;*/    
}