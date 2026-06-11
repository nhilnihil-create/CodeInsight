#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> L(M), R(M), D(M);
    vector<vector<Pll>> G(N);
    rep(i,M){
        cin >> L[i] >> R[i] >> D[i];
        L[i]--;R[i]--;
        G[L[i]].push_back(Pll(D[i], R[i]));
        G[R[i]].push_back(Pll(-D[i], L[i]));
    }
    vector<ll> dist(N,1e18);
    rep(i,N){
        if(dist[i] != 1e18) continue;
        queue<Pll> que;
        que.push(Pll(0,i));
        while(!que.empty()){
            ll cost = que.front().fi;
            ll v = que.front().se;
            que.pop();
            if(dist[v] != 1e18) continue;
            dist[v] = cost;
            for(auto& p:G[v]){
                ll dost = p.fi;
                ll u = p.se;
                que.push(Pll(cost+dost,u));
            }
        }
    }
    rep(i,M){
        if(dist[R[i]] - dist[L[i]] != D[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}