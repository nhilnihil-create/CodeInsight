#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (int i = m; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using PL = pair<long long, long long>;
const int INF = 1001001007;
const int MOD = 1000000007;
template <typename T>
void printvec(vector<T> &ar){
    rep(i,ar.size()-1) cout << ar[i] << " ";
    cout << ar[ar.size()-1] << endl;
}
template <typename Q>
void printvvec(vector<vector<Q>> &ar){
    rep(i,ar.size()){
        rep(j,ar[0].size()-1) cout << ar[i][j] << " ";
        cout << ar[i][ar[0].size()-1] << endl;
    }
}
template <typename S>
bool range(S a, S b, S x){
    return (a <= x && x < b);
}

void sihou(vector<vector<ll>> &p, int x, int y){
    p[x][y] = p[x][y+1] + p[x+1][y] + p[x][y-1] + p[x-1][y];
}

int main(){
    int n; cin >> n;
    vector<vector<int>> ti(n, vector<int>(10));
    rep(i,n)rep(j,10) cin >> ti[i][j];
    vector<vector<int>> pr(n, vector<int>(11));
    rep(i,n)rep(j,11) cin >> pr[i][j];
    ll mx = -1000000000;
    repp(i,1<<10,1){
        ll r = 0;
        vector<int> jo(10,0);
        rep(j,10){
            if (i>>j & 1) jo[j] = 1;
        }
        rep(j,n){
            int cnt = 0;
            rep(k,10) cnt += ti[j][k] * jo[k];
            r += pr[j][cnt];
        }
        mx = max(mx, r);
    }
    cout << mx << endl;
}