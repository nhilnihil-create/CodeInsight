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
    int n, m;
    cin >> n >> m;
    VVL xyz(n, VL(3));
    rep(i,n) cin >> xyz[i][0] >> xyz[i][1] >> xyz[i][2];

    ll ans = 0;
    rep(i, 1<<3){
        VI sgn(3, 1);
        rep(j, 3) if (i>>j & 1) sgn[j] *= -1;

        VL sums(n);
        rep(j,n){
            rep(k,3) sums[j] += xyz[j][k] * sgn[k];
        }
        sort(rall(sums));
        ll sum = 0;
        rep(j,m) sum += sums[j];

        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}