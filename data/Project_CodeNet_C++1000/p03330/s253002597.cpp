#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<int,int> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

//input
ll n,C;
ll d[40][40];
ll c[510][510];

ll iwakan[3][40];

int main(){
    cin >> n >> C;
    rep(i,C)rep(j,C){
        cin>>d[i][j];
    }
    rep(i,n)rep(j,n){
        cin>>c[i][j];
        c[i][j]--;
    }
    rep(k,C){
        rep(i,n){
            rep(j,n){
                iwakan[(i+j)%3][k]+=d[c[i][j]][k];
            }
        }
    }
    ll ans = INF;
    rep(i,C){
        rep(j,C){
            rep(k,C){
                if(i==j||j==k||k==i)continue;
                chmin(ans,iwakan[0][i]+iwakan[1][j]+iwakan[2][k]);
            }
        }
    }
    cout << ans << endl;


    return 0;
}

