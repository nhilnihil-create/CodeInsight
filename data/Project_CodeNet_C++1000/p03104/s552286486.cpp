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

ll f(ll x){
    if (x < 0) return 0;

    x++;
    ll ans = 0;
    rep(i, 50){
        ll loop = 1LL<<(i+1);
        ll cnt = (x / loop) * (loop / 2);
        cnt += max(0LL, (x % loop) - (loop / 2));

        if (cnt % 2 == 1){
            ans += 1LL<<i;
        }
    }
    return ans;
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll ans = f(b) ^ f(a-1);
    cout << ans << endl;
    return 0;
}
