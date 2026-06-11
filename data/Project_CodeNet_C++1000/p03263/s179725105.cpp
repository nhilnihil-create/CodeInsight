#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int H,W;
cin >> H >> W;
vvi a(H,vi(W));
rep(h,H) rep(w,W) cin >> a[h][w];

vvi ans;
rep(h,H) {
    rep(w,W-1) {
        if(a[h][w] % 2 == 1) {
            ans.push_back({h+1,w+1,h+1,w+2});
            a[h][w+1]++;
        }
    }
}
rep(h,H-1) {
    if(a[h][W-1] % 2 == 1) {
        ans.push_back({h+1,W,h+2,W});
        a[h+1][W-1]++;
    }
}
int N = SZ(ans);
cout << N << endl;
rep(i,N) {
    rep(j,4) {
        if(j < 3) cout << ans[i][j] << ' ';
        else cout << ans[i][j];
    }
    cout << endl;
}
return 0;
}