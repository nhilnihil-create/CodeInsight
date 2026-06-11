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
//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};
//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve(){
    ll n, h; cin >> n >> h;
    vector<ll> a, b;
    REP(i, n){
        ll ia, ib;
        cin >> ia >> ib;
        a.pb(ia); b.pb(ib);
    }
    sort(RALL(a));
    sort(RALL(b));
    ll mxa = a[0];
    ll res = 0;
    REP(i, n){
        if(h > 0){
            if(mxa < b[i]){
                h -= b[i];
                res++;
            }
        }
    }
    if(h > 0){
        res += h/mxa;
        if(h%mxa > 0) res++;
    }
    cout << res << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}