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
    int h, w, d;
    cin >> h >> w >> d;
    vector<vector<int>>board(h, vector<int>(w)),ans(d);
    rep(i, 0, h)rep(j, 0, w)cin >> board[i][j];
    map<int, pii>mp;
    rep(i, 0, h)rep(j, 0, w)mp[board[i][j]] = pii(i+1, j+1);
    rep(i, 0, d){
        int temp = i, dist = 0;
        while(temp<=h*w){
            ans[i].push_back(dist);
            dist += abs(mp[temp+d].first-mp[temp].first)
            +abs(mp[temp+d].second-mp[temp].second);
            temp += d;
        }
    }
    int q;
    cin >> q;
    vector<int>l(q),r(q);
    rep(i, 0, q)cin >> l[i] >> r[i];
    rep(i, 0, q){
        int p = l[i]%d;
        //rep(j, 0, ans[p].size())cout << ans[p][j] << endl;
        cout << ans[p][r[i]/d]-ans[p][l[i]/d] << endl;
    }
}