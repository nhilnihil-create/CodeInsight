#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define all(vec) vec.begin(), vec.end()
#define tmax(x, y, z) max((x), max((y), (z)))
#define tmin(x, y, z) min((x), min((y), (z)))
ll MM = 1000000000; ll mod = MM + 7; ll MMM=9223372036854775807;//2^63 -1
ll GCD(ll x, ll y){ if(y == 0) return x; else return GCD(y, x % y);}
ll LCM(ll x, ll y){ return x / GCD(x, y) * y;}
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true;} return false;}
const ll INF = 1LL << 60;
using Graph = vector<vector<ll>>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//cout << fixed << setprecision(10);

// 2*nに耐えるように
ll used_red[210];

int main(){
    ll n, x, y, ans = 0;
    cin >> n;
    vector<pair<ll, ll>> red(n), blue(n);
    rep(i, n){
        cin >> x >> y;
        red[i] = make_pair(x, y);
    }
    // x座標昇順
    sort(all(red));
    rep(i, n){
        cin >> x >> y;
        blue[i] = make_pair(x, y);
    }
    // x座標昇順
    sort(all(blue));

    for(auto pb: blue){
        ll ind_x, max_y = -1;
        for(auto pa: red){
            // redのx座標がblueのx座標以上になったらやめる
            if(pa.first >= pb.first) break;
            // ペア候補
            if(!used_red[pa.first] && pa.second < pb.second){
                // y座標の最大で貪欲
                if(chmax(max_y, pa.second)) ind_x = pa.first;
            }
        }
        // ペア候補が一つでも見つかっていたら
        if(max_y != -1){
            ans++;
            used_red[ind_x] = 1;
        }
    }

    cout << ans << endl;
}
