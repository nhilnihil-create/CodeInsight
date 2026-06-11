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

bool dpa[8005][20000];
bool dpb[8005][20000];
const ll TEMP = 10000;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);
//    ifstream in("/Users/hamath/CLionProjects/atcoder/abc/082/1_17.txt");
//    cin.rdbuf(in.rdbuf());
    string s;
    ll x,y;
    cin>>s>>x>>y;
    Vec a;
    Vec b;
    s += 'T';
    ll cnt = 0;
    ll dir = 0;
    bool firstT = true;
    ll start=0;

    rep(i,s.length()){
        if(s[i]=='T'){
            if(dir%2==0){
                if(!firstT){
                    a.pb(cnt);
                }
            }else{
                b.pb(cnt);
            }
            dir++;
            if(firstT){
                start = cnt;
                firstT = false;
            }
            cnt = 0;
        }else{
            cnt++;
        }
    }

    memset(dpa,false, sizeof(dpa));
    memset(dpb,false, sizeof(dpb));

    dpa[0][TEMP+start] = true;
    dpb[0][TEMP] = true;

    REP(i,1,a.size()+1){
        REP(j,TEMP-8005,TEMP+8005){
            if(j-a[i-1]>=0) dpa[i][j] |= dpa[i-1][j-a[i-1]];
            if(j+a[i-1]<=19999) dpa[i][j] |= dpa[i-1][j+a[i-1]];
        }
    }

    REP(i,1,b.size()+1){
        REP(j,TEMP-8005,TEMP+8005){
            if(j-b[i-1]>=0) dpb[i][j] |= dpb[i-1][j-b[i-1]];
            if(j+b[i-1]<=19999)dpb[i][j] |= dpb[i-1][j+b[i-1]];
        }
    }

//    dbg(a);
//    dbg(b);
//    dbg(start);
//    rep(i,6){rep(j,20){cerr<<dpb[i][TEMP+j-10]<<" ";}cerr<<endl;}

    Yes(dpa[a.size()][TEMP+x] & dpb[b.size()][TEMP+y]);
    return  0;
}
