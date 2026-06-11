#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<vi> lr(n+1,vi(n+1));
    rep(i,m){
        int l,r;
        cin >> l >> r;
        lr[l][r]++;
    }
    rep(i,n+1){
        rep(j,n){
            lr[i][j+1]+=lr[i][j];
        }
    }
    rep(i,n+1){
        rep(j,n){
            lr[j+1][i]+=lr[j][i];
        }
    }
    vi ans;
    rep(i,q){
        int x,y;
        cin >> x >> y;
        ans.push_back(lr[y][y]-lr[x-1][y]-lr[y][x-1]+lr[x-1][x-1]);
    }
    for(auto x:ans) cout << x << endl;
}