#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<int>> C(10 ,vector<int>(10));

    rep(i,10) {
        rep(j,10) {
            cin >> C[i][j];
        }
    }

    int V = 10;

    rep(k,V) {
        rep(i,V){
            rep(j,V) {
                C[i][j] = min(C[i][j], C[i][k]+C[k][j]);
            }
        }
    }

    ll ans = 0;

    rep(i,H*W){
        int a;
        cin >> a;

        if (a!=-1) {
            ans += C[a][1];
        }

    }
    cout << ans << endl;
}