#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<int,int> P;
typedef pair<ll,P> PP;
//typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = numeric_limits<ll>::max();

ll n,k;
vector<P>zahyo;

int main(){
    cin >> n >> k;
    zahyo.resize(n);
    rep(i,n){
        ll x,y;
        cin >> x >> y;
        zahyo[i]={x,y};
    }
    ll ans = INF;
    rep(i,n){
        rep(j,n){
            rep(ni,n){
                rep(nj,n){
                    ll x1,x2,y1,y2;
                    x1=zahyo[i].first;x2=zahyo[j].first;
                    y1=zahyo[ni].second;y2=zahyo[nj].second;
                    if(x1>x2)swap(x1,x2);
                    if(y1>y2)swap(y1,y2);
                    ll cnt = 0;
                    rep(l,n){
                        ll xnow=zahyo[l].first;
                        ll ynow=zahyo[l].second;
                        if(xnow<x1||xnow>x2)continue;
                        if(ynow<y1||ynow>y2)continue;
                        cnt++;
                    }
                    if(cnt>=k){
                        chmin(ans,(x2-x1)*(y2-y1));
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}

