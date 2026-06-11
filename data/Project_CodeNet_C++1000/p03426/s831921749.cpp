#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int h,w,d;
int mrk[1000000];
int rs[1000000];
P z[1000000];

int main(){
    cin >> h >> w >> d;
    int hw = h * w;
    rep(i,h){
        rep(j,w){
            int a;
            cin >> a;
            z[a]=make_pair(i,j);
        }
    }
    for(int i = 1; i<=hw-d;i++){
        int kyori = abs(z[i].first-z[i+d].first)+abs(z[i].second-z[i+d].second);
        mrk[i]=kyori;
    }
    for(int i = 1;i<=hw;i++){
        if(i-d<=0){
            rs[i]=mrk[i];
        }
        else{
            rs[i]=mrk[i]+rs[i-d];
        }
    }
    int q;
    cin >> q;
    rep(i,q){
        int l,r;
        cin >> l >> r;
        int res;
        if(l-d<=0){
            res = rs[r-d];
        }
        else{
            res = rs[r-d]-rs[l-d];
        }
        cout << res << endl;
    }
    return 0;
}
