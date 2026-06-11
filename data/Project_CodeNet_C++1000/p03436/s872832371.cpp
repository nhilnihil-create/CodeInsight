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

int main(){
    ll H,W;
    cin >> H >> W;
    vector<string>S(H);
    rep(i,H){
        cin >> S[i];
    }
    ll cnt = 0;
    rep(i,H){
        rep(j,W){
            if(S[i][j] == '.')cnt++;
        }
    }
    vector<vector<ll>> dist(H,vector<ll>(W,1e18));
    queue<pair<Pll,ll>> que;
    que.push(make_pair(Pll(0,0),1));
    while(!que.empty()){
        ll h = que.front().first.first;
        ll w = que.front().first.second;
        ll c = que.front().second;
        que.pop();
        if(!(0<=h && h<H)) continue;
        if(!(0<=w && w<W)) continue;
        if(S[h][w] == '#') continue;
        if(dist[h][w] != 1e18) continue;
        dist[h][w] = c;
        que.push(make_pair(Pll(h-1,w),c+1));
        que.push(make_pair(Pll(h+1,w),c+1));
        que.push(make_pair(Pll(h,w-1),c+1));
        que.push(make_pair(Pll(h,w+1),c+1));
    }
    if(dist[H-1][W-1] == 1e18){
        cout << -1 << endl;
    }else{
        cout << cnt - dist[H-1][W-1] << endl;
    }

}
