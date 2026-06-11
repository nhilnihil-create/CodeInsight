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
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;


int main(){
    int n , m , q;
    cin >> n >> m >> q;
    vector<vector<int>>accum(n+1,vector<int>(n+1)),board(n,vector<int>(n));
    vector<pii>query(q);
    rep(i, 0, m){
        int l, r;
        cin >> l >> r;
        l--,r--;
        board[l][r]++;
    }
    rep(i, 0, n){
        rep(j, 0, n){
            accum[i+1][j+1] = board[i][j];
        }
    }
    rep(i, 0, n){
        rep(j, 0, n+1){
            accum[i+1][j] += accum[i][j];
        }
    }
    rep(j, 0, n){
        rep(i, 0, n+1){
            accum[i][j+1] += accum[i][j];
        }
    }
    
    rep(i, 0, q){
        cin >> query[i].first >> query[i].second;
        query[i].first--;
        //query[i].second--;
    }
    rep(i, 0, q){
        int temp = accum[query[i].second][query[i].second]
        +accum[query[i].first][query[i].first]
        -accum[query[i].first][query[i].second]
        -accum[query[i].second][query[i].first];
        cout << temp << endl;
    }
    //rep(i, 0, n+1)cout << imos[i] << " ";
    //cout << endl;
}