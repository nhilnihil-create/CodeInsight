#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

vector<vector<ll>> G(10001);
vector<ll> memo(10001),c(10001);
priority_queue<ll> que;
ll ans = 0;
ll dfs(ll v, ll c){
    for(auto& u:G[v]){
        if(memo[u]!=0)continue;
        ll c2 = que.top();
        memo[u] = c2;
        que.pop();
        ans += min(c,c2);
        dfs(u,c2);
    }
    return 0;
}


int main(){
    ll N;
    cin >> N;
    ll a,b;
    rep(i,N-1){
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,N){
        cin >> c[i];
        que.push(c[i]);
    }
    ll t = que.top();
    memo[0] = t;
    que.pop();
    dfs(0,t);
    cout << ans << endl;
    PR(memo,N);
}