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

    VL sum;
    rep(i, x){
        rep(j, y){
            sum.push_back(a[i] + b[j]);
        }
    }
    sort(rall(sum));
    VL ans;
    rep(i, min(k, (int)sum.size())){
        rep(j, min(k, (int)c.size())){
            ans.push_back(sum[i] + c[j]);
        }
    }

    sort(rall(ans));
    rep(i,k) cout << ans[i] << endl;
    return 0;
}