#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define pb push_back
#define pf push_front
#define eb emplace_back
using namespace std;
typedef long long ll;
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b; return true;} return false;}
template<class t,class u> bool chmin(t&a,u b){if(a>b){a=b; return true;} return false;}
template<class t,class u> t MAX(t a,u b){if(a>=b) return a; return b;}
template<class t,class u> t MIN(t a,u b){if(a<=b) return a; return b;}
template<class t> int SIZE(t s){return (int)s.size();}
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using vvi=vc<vc<int>>;
using pi=pair<int,int>;
using vi=vc<int>;
void yes(){ cout << "Yes" << endl; }
void no(){ cout << "No" << endl; }
const long long INF = 1LL << 60;

/*
    ワーシャルフロイド法
    vvc<ll> dist(n,vc<ll>(n,INF));
    
    下のようにして距離を保存してください
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    
    distに i -> j の最短距離が入ります
    dist[i][j] が負の値の場合　負閉路です
*/

void war(vvc<ll>& dist){
    ll n = SIZE(dist);
    rep(k,n) rep(i,n) rep(j,n){
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }
}

int main(){
    cout << fixed << setprecision(20);
    ll n = 10;
    vvc<ll> dist(n,vc<ll>(n,INF));
    ll h,w; cin >> h >> w;
    rep(i,10){
        rep(j,10){
            cin >> dist[i][j];
            if(i == 1) dist[i][j] = 0;
        }
    }
    war(dist);
    ll ans = 0;
    rep(i,h){
        rep(j,w){
            int x; cin >> x;
            if(x == -1) continue;
            ans += dist[x][1];
        }
    }
    cout << ans << endl;
    return 0;
}
