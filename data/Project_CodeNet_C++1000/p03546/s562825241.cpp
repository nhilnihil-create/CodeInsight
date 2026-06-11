#include <bits/stdc++.h>
#define rep(i, n) for(long long int i = 0; i < n; i++)
#define _rep(i, m, n) for(long long int i = m; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
//const int N = 1000000;
const ll mod = 1000000007;
//using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
  
ll gcd(ll A, ll B){
    if(B == 0)return A;
    return gcd(B, A % B);
}
ll lcm(ll A, ll B){
    return A * (B / gcd(A, B));
}
using Edge = pair<int,int>;
using Graph = vector<vector<Edge>>;
Graph G;
  
/*------------------------------------------------------------------*/

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> c(10, vector<int>(10, INFINITY));
    rep(i, 10) rep(j, 10) cin >> c[i][j];

    rep(k, 10){
        rep(i, 10){
            rep(j, 10){
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
    ll ans = 0;
    rep(i, h){
        rep(j, w){
            int num; cin >> num;
            if(num == -1) continue;
            ans += c[num][1];
        }
    }
    cout << ans << endl;
}