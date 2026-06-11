#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>>board(10, vector<int>(10));
    rep(i, 0, 10)rep(j, 0, 10)cin >> board[i][j];
    rep(k, 0, 10){
        rep(i, 0, 10){
            rep(j, 0, 10){
                chmin(board[i][j], board[i][k]+board[k][j]);
            }
        }
    }
    int ans = 0;
    rep(i, 0, h*w){
        int a;
        cin >> a;
        if(a==-1)continue;
        ans += board[a][1];
    }
    cout << ans << endl;
}