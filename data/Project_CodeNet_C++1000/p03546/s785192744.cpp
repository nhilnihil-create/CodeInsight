#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;
typedef pair<int,int> pr;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){
    int d[10][10],a;
    ll h,w; cin >> h >> w;
    ll ans = 0;
    int V = 10;

    rep(i,V){
        rep(j,V) cin >> d[i][j];
    }

    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    rep(i,h){
        rep(j,w){
            cin >> a;
            if(a != -1 && a != 1)  ans += d[a][1];
        }
    }

    cout << ans;



}