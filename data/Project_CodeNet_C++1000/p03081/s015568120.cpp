#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
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
#define sum(v) accumulate(ALL(v),0)
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

string s;
ll simulate(ll pos,  vector<pair<char,char>> vp){
    rep(i,vp.size()){
        if(s[pos]!=vp[i].fi)continue;
        if(vp[i].se=='L'){
            pos--;
        }else{
            pos++;
        }
        if(pos<0)return -1;
        if(pos>=s.size())return 1;
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);

    ll n,q;
    cin>>n>>q;
    cin>>s;
    vector<pair<char,char>> vp(q);
    rep(i,q){
        cin>>vp[i].fi>>vp[i].se;
    }
    ll ans=0;

    ll lfall = 0;
    ll rfall = 0;

    ll L=-1,R=n;
    while(L+1<R){
        ll c = (L+R)/2;
        bool ok = [&]{
            return simulate(c,vp)==-1;
        }();
        if(ok){
            L = c;
        }else{
            R = c;
        }
    }
    lfall = L;

    L=-1,R=n;
    while(L+1<R){
        ll c = (L+R)/2;
        bool ok = [&]{
            return simulate(c,vp)==1;
        }();
        if(ok){
            R = c;
        }else{
            L = c;
        }
    }
    rfall = R;

    lfall =(lfall+1);
    rfall = (n-rfall);
    cout<<n-lfall-rfall<<endl;
    return  0;
}
