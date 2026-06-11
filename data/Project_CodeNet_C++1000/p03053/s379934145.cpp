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

ll X[4] = {1,0,-1,0};
ll Y[4] = {0,1,0,-1};

int main(){
    ll H,W;
    cin >> H >> W;
    vector<string> A(H);
    queue<Pll> que;
    vector<vector<ll>> memo(H, vector<ll>(W));
    vector<vector<ll>> c(H, vector<ll>(W,1e18));
    rep(i,H){
        cin >> A[i];
    }
    rep(i,H){
        rep(j,W){
            if(A[i][j] == '#'){
                que.push(Pll(i,j));
                c[i][j] = 0;
            }
        }
    }
    ll ans = 0;
    while(!que.empty()){
        ll h = que.front().first;
        ll w = que.front().second;
        que.pop();
        if(!(0 <= h && h < H)) continue;
        if(!(0 <= w && w < W)) continue;        
        if(memo[h][w] != 0) continue;
        memo[h][w] = 1;
        rep(i,4){
            if(!(0 <= h+Y[i] && h+Y[i] < H)) continue;
            if(!(0 <= w+X[i] && w+X[i] < W)) continue;    
            que.push(Pll(h+Y[i],w+X[i]));
            c[h+Y[i]][w+X[i]] = min(c[h+Y[i]][w+X[i]], c[h][w] + 1);
        }
    }
    rep(i,H){
        rep(j,W){
            cmax(ans,c[i][j]);
        }
    }
    cout << ans << endl;
}