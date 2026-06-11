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
const ll inf_l = 1e18;
const int MAX = 1e5;

ll dis(vll &s, vll &t, ll st) {
    int index_r = lower_bound(all(s),st)-s.begin();
    int index_l = index_r - 1;
    int index_rr = lower_bound(all(t),s[index_r])-t.begin();
    int index_rl = index_rr - 1;
    int index_lr = upper_bound(all(t),s[index_l])-t.begin();
    int index_ll = index_lr - 1;
    ll dis_ll = (st-s[index_l])+(s[index_l]-t[index_ll]);
    ll dis_lr = (st-s[index_l])+(t[index_lr]-s[index_l]);
    ll dis_rr = (s[index_r]-st)+(s[index_r]-t[index_rl]);
    ll dis_rl = (s[index_r]-st)+(t[index_rr]-s[index_r]);
    return min({dis_ll,dis_lr,dis_rr,dis_rl});
}

int main() {
    int a, b, q; cin >> a >> b >> q;
    vll s(a+2);
    s[0] = -inf_l;
    REP(i,a+1) cin >> s[i];
    s[a+1] = inf_l;
    vll t(b+2);
    t[0] = -inf_l;
    REP(i,b+1) cin >> t[i];
    t[b+1] = inf_l;
    rep(i,q) {
        ll x; cin >> x;
        cout << min(dis(s,t,x),dis(t,s,x)) << endl;
    }
    return 0;
}