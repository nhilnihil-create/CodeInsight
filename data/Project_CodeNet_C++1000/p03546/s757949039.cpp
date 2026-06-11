#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long
#define INF  1<<29

void warshal_flotd(int n,vector<vector<int> > &d){
    rep(k,n){
        rep(i,n){
            rep(j,n){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    int h,w; cin >> h >> w;
    vector<vector<int> > c(10,vector<int>(10));
    vector<vector<int> > A(h,vector<int>(w));
    rep(i,10) rep(j,10) cin >> c[i][j];
    rep(i,h) rep(j,w) cin >> A[i][j];
    warshal_flotd(10,c);
    ll ans = 0;
    rep(i,h){
        rep(j,w){
            int a = A[i][j];
            if(a==-1) continue;
            ans += c[a][1];
        }
    }
    cout << ans << endl;
}