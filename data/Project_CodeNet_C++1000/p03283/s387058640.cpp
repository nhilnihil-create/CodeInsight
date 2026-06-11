#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int t[505][505], c[505][505];

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    rep(i,m){
        int l, r;
        cin >> l >> r;
        t[l][r]++;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            c[i][j] = c[i][j-1] + t[i][j];
        }
    }

    rep(i,q){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int j = l; j <= r; j++){
            ans += c[j][r] - c[j][l-1];
        }
        cout << ans << endl;
    }
    return 0;
}