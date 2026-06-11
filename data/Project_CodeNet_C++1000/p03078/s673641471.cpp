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

int main(){
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    VL a(x), b(y), c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];

    sort(rall(a));
    sort(rall(b));
    sort(rall(c));

    VL ans;
    rep(l, x){
        rep(m, y){
            rep(n, z){
                if ((l+1) * (m+1) * (n+1) <= k) ans.push_back(a[l] + b[m] + c[n]);
                else break;
            }
        }
    }
    sort(rall(ans));
    rep(i,k) cout << ans[i] << endl;
    return 0;
}