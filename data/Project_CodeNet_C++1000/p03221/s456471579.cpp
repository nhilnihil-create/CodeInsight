#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p){os<<"("<<p.first<<","<< p.second<<")";return os;}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v){os<<"{";REP(i,(int)v.size()){if(i)os<<",";os<<v[i];}os<<"}";return os;}
template <typename T, size_t S> void printArray(const T (&array)[S]){for(auto val : array)std::cout << val << ", ";std::cout << "\n";}
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
const double PI=acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;
template<class T>inline bool chmax(T& a, T b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T& a, T b){if(a > b){a = b; return 1;}return 0;}
const ll INF = 1LL<<60;
//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};
//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve(){
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> vp, origin;
    REP(i, m){
        ll p, y; cin >> p >> y;
        vp.pb({p, y});
        origin.pb({p, y});
    }
    sort(ALL(vp));
    map<ll, ll> mp;
    ll id = vp[0].fi, cnt = 0;
    for(int i=0; i<vp.size(); i++){
        ll nid = vp[i].fi;
        cnt++;
        if(nid == id){
            mp[vp[i].se] = cnt;
        }
        else{
            cnt = 1;
            mp[vp[i].se] = cnt;   
        }
        id = nid;
    }
    REP(i, m){
        string s, t;
        ll l = origin[i].fi, r = mp[origin[i].se];
        string sleft = to_string(l), sright = to_string(r);
        cout << setfill('0') << right << setw(6) << sleft;
        cout << setfill('0') << right << setw(6) << sright << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}