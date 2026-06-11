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
    ll n; cin >> n;
    vector<ll> ev(100001, 0), od(100001, 0);
    REP(i, n){
        ll v; cin >> v;
        if(i%2 == 0) ev[v]++;
        else od[v]++;
    }
    vector<pair<ll, ll>> eve, odd;
    REP(i, 100001){
        if(ev[i] != 0) eve.pb({ev[i], i});
        if(od[i] != 0) odd.pb({od[i], i});
    }
    sort(RALL(eve));
    sort(RALL(odd));
    //cout << eve << endl;
    //cout << odd << endl;
    ll evesiz = eve.size(), oddsiz = odd.size();
    if(evesiz == 1 && oddsiz == 1){
        if(eve[0].se == odd[0].se) cout << n/2 << endl;
        else cout << 0 << endl;
    }
    else{
        if(eve[0].se == odd[0].se){
            ll reseve = 0, resodd = 0;
            //eve[0].seを採用する
            for(int i=0; i<evesiz; i++){
                if(i != 0) reseve += eve[i].fi;
            }
            for(int i=0; i<oddsiz; i++){
                if(i != 1) reseve += odd[i].fi;
            }
            //odd[0].seを採用する
            for(int i=0; i<evesiz; i++){
                if(i != 1) resodd += eve[i].fi;
            }
            for(int i=0; i<oddsiz; i++){
                if(i != 0) resodd += odd[i].fi;
            }
            cout << min(reseve, resodd) << endl;
        }
        else{
            ll res = 0;
            for(int i=0; i<evesiz; i++){
                if(i != 0) res += eve[i].fi;
            }
            for(int i=0; i<oddsiz; i++){
                if(i != 0) res += odd[i].fi;
            }
            cout << res << endl;
        }
    }
    
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}