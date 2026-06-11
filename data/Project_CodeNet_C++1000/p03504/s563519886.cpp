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
    int n, c;
    cin >> n >> c;
    vector<vector<int>>st(c,vector<int>(200200));
    rep(i, 0, n){
        int p, q, r;
        cin >> p >> q >> r;
        p*=2;
        q*=2;
        r--;
        st[r][p-1]++;
        st[r][q+1]--;
    }
    rep(i, 0, c){
        rep(j, 1, 200200){
            st[i][j] += st[i][j-1];
        }
    }
    rep(i, 0, c)rep(j, 1, 200200)if(st[i][j]>1)st[i][j]=1;
    int ans = -1;
    rep(j, 0, 200200){
        int temp = 0;
        rep(i, 0, c){
            temp += st[i][j];
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
}