#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<P> VP;
typedef vector<vector<ll>> VV;
typedef vector<vector<int>> VVi;
typedef vector<vector<vector<ll>>> VVV;
typedef vector<vector<vector<vector<ll>>>> VVVV;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF=1e18+18;
const ll MAX=100005;
ll MOD;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)
#ifdef LOCAL
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}
#define dbgarr(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}
#define dbgdp(n,arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;
#define dbgmint(n,arr) rep(i,n){cerr<<arr[i].x<<" ";}cerr<<endl;
#define dbgarrmint(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j].x<<" ";}cerr<<endl;}
#else
#define dbg(...)
#define dbgmap(...)
#define dbgarr(...)
#define dbgdp(...)
#define dbgmint(...)
#define dbgarrmint(...)
#endif
#define out(a) cout<<a<<endl
#define out2(a,b) cout<<a<<" "<<b<<endl
#define vout(v) rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl
#define Uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define fi first
#define se second

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,v.size())i>>v[j];return i;}

// vector
template<typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
    int len=v.size();
    for(int i=0; i<len; ++i) {
        s<<v[i];
        if(i<len-1) s<<"	";
    }
    return s;
}

// 2 dimentional vector
template<typename T>
ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {
    int len=vv.size();
    for(int i=0; i<len; ++i) {
        s<<vv[i]<<endl;
    }
    return s;
}



void simulate(){
    ll n = 20;
//    vector<VP> vp(n+1);
//    rep(now,n+1){
//        rep(j,n+1){
//            rep(i,j){
//                if( (i | j) <=  now){
//                    vp[now].emplace_back(i,j);
//                }
//            }
//        }
//        sort(ALL(vp[now]));
//    }
//    dbg(vp);

    exit(0);
}

void simulate2(){
    ll n = 16;
    VV g (n,Vec(n,INF));
    rep(now,n){
        rep(j,n){
            rep(i,j){
                if( (i | j) <=  now){
                    chmin(g[i][j],now);
                    chmin(g[j][i],now);
                }
            }
        }
    }
    rep(now,n){
        g[now][now] = 0;
    }
    dbg(g);
    exit(0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);

    //simulate2();

    auto chmax = [&](P &a,P &b){
        if(a.fi<b.fi){
            a.se = max(a.fi,b.se);
            a.fi = b.fi;
        }else{
            a.se = max(a.se,b.fi);
        }
    };
    ll n;
    cin>>n;
    ll bits = 1<<n;

    Vec a(bits);
    cin>>a;
    VP dp(bits);

    rep(bit, bits){
        dp[bit] = mp(a[bit],-INF);
    }

    rep(i,n){
        rep(bit,bits){
            if(bit & (1<<i)){
                chmax(dp[bit],dp[bit^(1<<i)]);
            }
        }
    }
    ll ans=-INF;
    rep(bit,bits){
        ll tmp = dp[bit].fi+dp[bit].se;
        ans = max(ans,tmp);
        if(bit)out(ans);
    }
    return  0;
}
