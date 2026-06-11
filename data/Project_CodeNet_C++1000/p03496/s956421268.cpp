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

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF=1e18+18;
const ll MAX=100005;
const ll MOD=1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}
#define dbgarr(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}
#define dbgdp(n,arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;
#define Uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define fi first
#define se second

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);

    ll n;
    cin>>n;
    Vec a(n);
    rep(i,n)cin>>a[i];
    ll min = INF;
    ll max = -INF;
    ll mini = 0;
    ll maxi = 0;
    rep(i,n){
        if(chmin(min,a[i])){
            mini = i;
        }
        if(chmax(max,a[i])){
            maxi = i;
        }
    }
    VP res;
//    dbg(min)
//    dbg(max)
    if(abs(min)>max){
        rep(i,n){
            if(i!=mini){
                res.emplace_back(mini,i);
            }
        }
    }else{
        rep(i,n){
            if(i!=maxi){
                res.emplace_back(maxi,i);
            }
        }
    }
    if(abs(min)>max){
        PER(i,n-1,1){
            res.emplace_back(i,i-1);
        }
    } else{
        REP(i,1,n){
            res.emplace_back(i-1,i);
        }
    }
    bool debug = false;
    cout<<res.size()<<endl;
    rep(i,res.size()){
        cout<<res[i].fi+1<<" "<<res[i].se+1<<endl;
        if(debug){
            a[res[i].se] += a[res[i].fi];
        }
    }
    if(debug){
        dbg(a);
    }
    return  0;
}
