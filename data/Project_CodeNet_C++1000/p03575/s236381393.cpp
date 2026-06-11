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
    int n, m;
    cin >> n >> m;
    vector<pii>ab(m);
    vector<vector<int>>board(n, vector<int>(n, 10000));
    rep(i, 0, n){
        rep(j, 0, n){
            if(i==j)board[i][j]=0;
        }
    }
    rep(i, 0, m){
        cin>> ab[i].first >> ab[i].second;
        ab[i].first--;
        ab[i].second--;
        board[ab[i].first][ab[i].second]=1;
        board[ab[i].second][ab[i].first]=1;
    }
    int cnt = 0;
    rep(i, 0, m){
        vector<vector<int>>temp = board;
        temp[ab[i].first][ab[i].second] = 10000;
        temp[ab[i].second][ab[i].first] = 10000;
        rep(k, 0, n){
            rep(s, 0, n){
                rep(g, 0, n){
                    chmin(temp[s][g], temp[s][k]+temp[k][g]);
                }
            }
        }
        bool p = false;
        rep(j, 0, n)rep(k, 0, n)if(temp[j][k]==10000)p= true;
        if(p)cnt++;
    }
    cout << cnt << endl;
}