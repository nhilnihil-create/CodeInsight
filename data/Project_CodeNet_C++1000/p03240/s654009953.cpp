#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int n;
vector<ll>x,y,h;
ll cx,cy,ch;
bool solve(){
    rep(i,n){
        ll now = max(ch-abs(x[i]-cx)-abs(y[i]-cy),0LL);
        if(now!=h[i])return false;
    }
    return true;
}

int main(){
    cin >> n;
    x.resize(n);
    y.resize(n);
    h.resize(n);
    rep(i,n)cin>>x[i]>>y[i]>>h[i];
    rep(i,101){
        rep(j,101){
            cx = i;
            cy = j;
            rep(k,n){
                if(h[k]!=0){
                    ch = abs(x[k]-cx) + abs(y[k]-cy) + h[k];
                    break;
                }
            }
            if(solve()){
                cout << cx << ' ' << cy << ' ' << ch << endl;
                return 0;
            }

        }
    }
    return 0;
}
