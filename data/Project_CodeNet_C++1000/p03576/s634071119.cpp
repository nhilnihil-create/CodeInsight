#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1LL<<62;
const int MAX = 1e5;

int main() {
    int n, K; cin >> n >> K;
    vector<pair<ll,ll>> cood(n);
    rep(i,n) {
        ll x, y; cin >> x >> y;
        cood[i] = P(x,y);
    }
    sort(all(cood));
    ll ans = inf_l;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ll side = cood[j].first-cood[i].first;
            vll tmp;
            for (int k = i; k <= j; k++) {
                tmp.push_back(cood[k].second);
            }
            if (tmp.size() < K) continue;
            sort(all(tmp));
            for (int k = 0; k <= tmp.size()-K; k++) {
                ll vertical = tmp[k+K-1]-tmp[k];
                ans = min(ans,side*vertical);
            }
        }
    }
    cout << ans << endl;
}